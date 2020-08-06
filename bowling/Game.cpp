#include "Game.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

void Game::loadFromFile(const std::string& fileName) {
    std::fstream file(fileName, std::ios_base::in);
    if (!file.good()) {
        std::cerr << "file " << fileName << " could not be opened!\n";
        abort();
    }
    std::string lineText{};
    while (getline(file, lineText)) {
        int currentCharIndex = 0;
        PlayerData player;
        fillPlayerName(currentCharIndex, player.Name, lineText);
        fillPlayerRolls(currentCharIndex, player.Rolls, lineText);
        players.push_back(player);
    }
    file.close();
}

void Game::fillPlayerName(int& currentCharIndex, std::string& playerName, const std::string& lineText) {
    for (currentCharIndex; currentCharIndex < lineText.size(); ++currentCharIndex) {
        if (lineText[currentCharIndex] != ':') {
            playerName += lineText[currentCharIndex];
        } else {
            currentCharIndex++;
            break;
        }
    }

}

void Game::fillPlayerRolls(int& currentCharIndex, std::vector<Frame>& playerRolls, const std::string& lineText) {
    for (currentCharIndex; currentCharIndex < lineText.size(); ++currentCharIndex) {
        if (lineText[currentCharIndex] == 'X') {
            playerRolls.push_back(Frame('X', ' '));
            currentCharIndex++;
        } else {
            playerRolls.push_back(
                Frame(lineText[currentCharIndex], lineText[currentCharIndex + 1]));
            currentCharIndex += 2;
        }
        if (playerRolls.size() == 10) {
            if (lineText[currentCharIndex - 1] == 'X') {
                playerRolls.push_back(Frame(lineText[currentCharIndex + 2],
                                            lineText[currentCharIndex + 3]));
            } else if (lineText[currentCharIndex - 1] == '/') {
                playerRolls.push_back(Frame(lineText[currentCharIndex + 2], ' '));
            }
            break;
        }
    }
}
