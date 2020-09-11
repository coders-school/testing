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

bool Game::isLastFrame(int frameCount) const {
    return frameCount == 10;
}

bool Game::isStrike(char currentRoll) const {
    return currentRoll == 'X';
}

bool Game::isStrike(const Frame& frame) const {
    return frame.getFirstRoll() == 'X' ? true : false;
}

bool Game::isSpare(char nextRoll) const {
    return nextRoll == '/';
}

bool Game::isSpare(const Frame& frame) const {
    return frame.getSecondRoll() == '/' ? true : false;
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

std::vector<Frame> Game::conversionCharNumbersToInt(const std::vector <Frame>& rolls) const {
    std::vector<Frame> convertedRolls {};
    Frame currentFrame {};
    char conversionNumber = '0';

    for (size_t i = 0; i < rolls.size(); i++) {
        size_t firstRoll = rolls[i].getFirstRoll();
        size_t secondRoll = rolls[i].getSecondRoll();
        if (!isStrike(rolls[i]) && !isSpare(rolls[i])) {
            firstRoll = (rolls[i].getFirstRoll() - conversionNumber);
            secondRoll = (rolls[i].getSecondRoll() - conversionNumber);
        } 
        if (isSpare(rolls[i])) {
            firstRoll = (rolls[i].getFirstRoll() - conversionNumber);
        }
        currentFrame = (Frame(firstRoll, secondRoll));
        convertedRolls.push_back(currentFrame);
    }
    return convertedRolls;
}

size_t Game::countFramesWithoutStrikeOrSpare(const std::vector<Frame>& rolls) const {
    size_t totalPointsWithoutStrikeNorSpare = 0;
    for (size_t i = 0; i < rolls.size(); i++) {
        if (!isStrike(rolls[i]) && !isSpare(rolls[i])) {
            totalPointsWithoutStrikeNorSpare += (rolls[i].getFirstRoll() + rolls[i].getSecondRoll());
        } 
    }
    return totalPointsWithoutStrikeNorSpare;
}

size_t Game::countOnlyStrikeFrames(const std::vector<Frame>& rolls) const {
    size_t totalOnlyStrikePoints = 0;
    for (size_t i = 0; i < rolls.size(); i++) {
        if (isStrike(rolls[i])) {
            totalOnlyStrikePoints += 10;
            if ((i + 1) != rolls.size()) {
                if (isStrike(rolls.at(i + 1)) || isSpare(rolls.at(i + 1))) {
                    totalOnlyStrikePoints += 10;
                } else {
                    totalOnlyStrikePoints += (rolls[i + 1].getFirstRoll() + rolls[i + 1].getSecondRoll());
                }
            }
        }
    }
    return totalOnlyStrikePoints;
}

size_t Game::countOnlySpareFrames(const std::vector<Frame>& rolls) const {
    size_t totalOnlySparePoints = 0;
    for (size_t i = 0; i < rolls.size(); i++) {
        if (isSpare(rolls[i])) {
            totalOnlySparePoints += 10;
            if ((i + 1) != rolls.size()) {
                if (isStrike(rolls.at(i + 1))) {
                    totalOnlySparePoints += 10;
                } else {
                    totalOnlySparePoints += rolls[i + 1].getFirstRoll();
                }
            }
        }
    }
    return totalOnlySparePoints;
}

size_t Game::countPoints(const std::vector<Frame>& rolls) const {
    size_t totalPoints = 0;
    auto convertedRolls = conversionCharNumbersToInt(rolls);
    totalPoints += countFramesWithoutStrikeOrSpare(convertedRolls);
    totalPoints += countOnlyStrikeFrames(convertedRolls);
    totalPoints += countOnlySpareFrames(convertedRolls);
    return totalPoints;
}

std::string Game::getOutputString(int laneNumber) const {
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
        output += player.name + " " + std::to_string(countPoints(player.rolls)) + "\n";
    }
    return output;
}

void Game::printOutput(std::ostream& os, int laneNumber) const {
    os << getOutputString(laneNumber);
}
