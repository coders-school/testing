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
        playerRolls = getPlayerRolls(file);
        if (!file.eof()) {
            if (std::find_if(players.begin(), players.end(), [&](auto& player) {
                    return player.getName() == playerName && player.getRolls() == playerRolls;
                }) == players.end()) {
                players.emplace_back(PlayerData(playerName, playerRolls));
            }
        }
    }
    file.close();
}

std::vector<Frame> Game::getPlayerRolls(std::ifstream& file) {
    std::vector<Frame> playerRolls{};
    std::string line{};
    std::getline(file, line);
    playerRolls = getFrames(line);
    return playerRolls;
}

std::vector<Frame> Game::getFrames(const std::string& line) {
    std::vector<Frame> playerRolls{};
    Frame currentFrame{};
    for (int currentChar = 0, frameNumber = 1; currentChar < line.size(); ++frameNumber) {
        if (isStrike(line[currentChar])) {
            currentFrame = Frame('X', ' ');
            incrementCharForStrike(currentChar, frameNumber);
        } else if (isSpare(line[currentChar + 1])) {
            currentFrame = Frame(line[currentChar], '/');
            incrementCharForSpare(currentChar, frameNumber);
        } else {
            currentFrame = getRegularFrame(line, currentChar);
            currentChar += 3;
        }
        playerRolls.push_back(currentFrame);
    }
    return playerRolls;
}

Frame Game::getRegularFrame(const std::string& rolls, int currentRoll) const {
    if (currentRoll == rolls.size() - 1) {
        return Frame(rolls[currentRoll], ' ');
    }
    return Frame(rolls[currentRoll], rolls[currentRoll + 1]);
}

void Game::incrementCharForStrike(int& currentRoll, int frameNumber) const {
    currentRoll += 2;
    if (isLastFrame(frameNumber)) {
        currentRoll++;
    }
}

void Game::incrementCharForSpare(int& currentRoll, int frameNumber) const {
    currentRoll += 3;
    if (isLastFrame(frameNumber)) {
        currentRoll++;
    }
}

bool Game::isLastFrame(int frameNumber) const {
    return frameNumber == 10;
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
