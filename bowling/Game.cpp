#include "Game.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

void Game::loadFromFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios_base::in);
    if (!file.good()) {
        std::cerr << "file " << filePath << " could not be opened!\n";
        abort();
    }
    while (!file.eof()) {
        PlayerData player;
        std::getline(file, player.name, ':');
        loadPlayerRolls(file, player.rolls);
        if (!file.eof()) {
            players.push_back(player);
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
            currentRoll++;
            if (isLastFrame(frameCount)) {
                currentRoll++;
            }
        } else if (isSpare(rolls[currentRoll + 1])) {
            currentFrame = Frame(rolls[currentRoll], '/');
            currentRoll += 2;
            if (isLastFrame(frameCount)) {
                currentRoll++;
            }
        } else {
            currentFrame = Frame(rolls[currentRoll], rolls[currentRoll + 1]);
            currentRoll += 2;
        }
        frameCount++;
        playerRolls.push_back(currentFrame);
    }
}

bool Game::isLastFrame(int frameCount) {
    return frameCount == 10;
}

bool Game::isStrike(char currentRoll) {
    return currentRoll == 'X';
}

bool Game::isSpare(char nextRoll) {
    return nextRoll == '/';
}

Game::Status Game::getGameStatus() const {
    if (players.size() == 0) {
        return Game::Status::NO_GAME;
    }
    if (std::any_of(players.begin(), players.end(), [](const PlayerData& player) {
            return !(player.rolls.size() == 10 || player.rolls.size() == 11);
        })) {
        return Game::Status::IN_PROGRESS;
    }
    if (std::all_of(players.begin(), players.end(), [](const PlayerData& player) {
            return player.rolls.size() == 10 || player.rolls.size() == 11;
        })) {
        return Game::Status::FINISHED;
    }
    return Game::Status::NO_GAME;
}

std::string Game::getOutputString(int laneNumber) {
    std::string output{"### Lane " + std::to_string(laneNumber) + ": "};
    switch(getGameStatus()) {
        case Status::FINISHED:
        output += "game finished";
        break;
        case Status::IN_PROGRESS:
        output += "game in progress";
        break;
        case Status::NO_GAME:
        output += "no game";
    }
    output += " ###\n";
    for (auto& player : players) {
        output += player.name + " " + std::to_string(getPlayerScore(player)) + "\n";
    }
    return output;
}

int Game::getPlayerScore(const PlayerData& player) {
    return -1;
}

void Game::printOutput(std::ostream& os, int laneNumber) {
    os << getOutputString(laneNumber);
}
