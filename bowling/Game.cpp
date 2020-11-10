#include "Game.hpp"
#include "Frame.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace fs = std::filesystem;

Game::Game(const fs::path& filePath) {
    loadFromFile(filePath.string());
}

void Game::loadFromFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios_base::in);
    if (!file.good()) {
        throw std::invalid_argument("file " + filePath + " could not be opened!\n");
    }
    while (!file.eof()) {
        std::string playerName{};
        std::vector<Frame> playerRolls{};
        std::getline(file, playerName, ':');
        loadPlayerRolls(file, playerRolls);
        if (!file.eof()) {
            players.emplace_back(PlayerData(playerName, playerRolls));
        }
    }
    file.close();
}

void Game::loadPlayerRolls(std::ifstream& file, std::vector<Frame>& playerRolls) {
    std::string rolls{};
    Frame currentFrame{};
    int frameCount = 1;
    std::getline(file, rolls);
    for (int currentRoll = 0; currentRoll < rolls.size(); ++currentRoll) {
        if (isStrike(rolls[currentRoll])) {
            currentFrame = Frame('X', ' ');
            incrementStrikeCounters(currentRoll, frameCount);
        } else if (isSpare(rolls[currentRoll + 1])) {
            currentFrame = Frame(rolls[currentRoll], '/');
            incrementSpareCounters(currentRoll, frameCount);
        } else {
            currentFrame = getRegularFrame(rolls, currentRoll);
            currentRoll += 2;
        }
        frameCount++;
        playerRolls.push_back(currentFrame);
    }
}

Frame Game::getRegularFrame(const std::string& rolls, int currentRoll) const {
    if (currentRoll == rolls.size() - 1) {
        return Frame(rolls[currentRoll], ' ');
    }
    return Frame(rolls[currentRoll], rolls[currentRoll + 1]);
}

void Game::incrementStrikeCounters(int& currentRoll, int frameCount) const {
    currentRoll++;
    if (isLastFrame(frameCount)) {
        currentRoll++;
    }
}

void Game::incrementSpareCounters(int& currentRoll, int frameCount) const {
    currentRoll += 2;
    if (isLastFrame(frameCount)) {
        currentRoll++;
    }
}

bool Game::isLastFrame(int frameCount) const {
    return frameCount == 10;
}

bool Game::isStrike(char currentRoll) const {
    return currentRoll == 'X';
}

bool Game::isSpare(char nextRoll) const {
    return nextRoll == '/';
}

Game::Status Game::getGameStatus() const {
    if (players.size() == 0) {
        return Game::Status::NO_GAME;
    }
    if (std::any_of(players.begin(), players.end(), [](const PlayerData& player) {
            return !(player.getRolls().size() == 10 || player.getRolls().size() == 11);
        })) {
        return Game::Status::IN_PROGRESS;
    }
    if (std::all_of(players.begin(), players.end(), [](const PlayerData& player) {
            return player.getRolls().size() == 10 || player.getRolls().size() == 11;
        })) {
        return Game::Status::FINISHED;
    }
    return Game::Status::NO_GAME;
}

std::string Game::getOutputString(int laneNumber) const {
    std::stringstream stream{};
    stream << "### Lane " << laneNumber << ": ";
    switch (getGameStatus()) {
        case Status::FINISHED:
            stream << "game finished";
            break;
        case Status::IN_PROGRESS:
            stream << "game in progress";
            break;
        case Status::NO_GAME:
            stream << "no game";
    }
    stream << " ###\n";
    for (auto& player : players) {
        if (player.getName() != "") {
            stream << player.getName() << " " << player.countPoints() << "\n";
        } else {
            stream << player.countPoints() << "\n";
        }
    }
    return stream.str();
}

bool Game::operator==(const Game& rhs) const {
    return players == rhs.players;
}
