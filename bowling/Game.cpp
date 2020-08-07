#include "Game.hpp"

#include <fstream>
#include <iostream>

void Game::loadFromFile(const std::string& fileName) {
    std::fstream file(fileName, std::ios_base::in);
    if (!file.good()) {
        std::cerr << "file " << fileName << " could not be opened!\n";
        abort();
    }
    while (!file.eof()) {
        PlayerData player;
        std::getline(file, player.Name, ':');
        loadPlayerRolls(file, player.Rolls);
        players.push_back(player);
    }
    file.close();
}

void Game::loadPlayerRolls(std::fstream& file, std::vector<Frame>& playerRolls) {
    std::string frame;
    while (true) {
        while (frame.empty()) {
            std::getline(file, frame, '|');
        }
        if (frame[0] == 'X') {
            frame += ' ';
        }
        playerRolls.push_back(Frame(frame[0], frame[1]));
        if (frame.find('\n') != std::string::npos) {
            break;
        }
        frame.erase();
    }
}
