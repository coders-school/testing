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
        players.push_back(player);
    }
    file.close();
}

void Game::loadPlayerRolls(std::ifstream& file, std::vector<Frame>& playerRolls) {
    std::string frame;
    while (true) {
        while (frame.empty()) {
            std::getline(file, frame, '|');
        }
        if (frame[0] == 'X' && playerRolls.size() <= 10) {
            frame += ' ';
        }
        if (spare(playerRolls) && lastFrame(playerRolls)) {
            playerRolls.push_back(Frame(frame[0], ' '));
        } else {
            playerRolls.push_back(Frame(frame[0], frame[1]));
        }
        if (lineEnds(frame)) {
            if (!file.eof()) {
                int characterCount = frame.size() - frame.find('\n');
                putBackCharacters(file, characterCount);
            }
            break;
        }
        frame.erase();
    }
}

bool Game::lineEnds(const std::string& text) {
    return text.find('\n') != std::string::npos;
}

void Game::putBackCharacters(std::ifstream& file, int count) {
    for (int i = 0; i < count; ++i) {
        file.unget();
    }
}

bool Game::spare(const std::vector<Frame>& playerRolls) {
    return playerRolls.size() == 10;
}

bool Game::lastFrame(const std::vector<Frame>& playerRolls) {
    return playerRolls.back().secondRoll == '/';
}
