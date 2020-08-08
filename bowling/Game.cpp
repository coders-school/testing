#include "Game.hpp"

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
    std::getline(file, rolls);
    for (int currentRoll = 0; currentRoll < rolls.size(); ++currentRoll) {
        if (rolls[currentRoll] == 'X') {
            currentFrame = Frame('X', ' ');
            currentRoll++;
        } else if (rolls[currentRoll + 1] == '/') {
            currentFrame = Frame(rolls[currentRoll], '/');
            currentRoll += 2;
        } else {
            currentFrame = Frame(rolls[currentRoll], rolls[currentRoll + 1]);
            currentRoll += 2;
        }
        playerRolls.push_back(currentFrame);
    }
}
