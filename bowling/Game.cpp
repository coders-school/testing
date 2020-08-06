#include "Game.hpp"

#include <fstream>
#include <iostream>

void Game::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.good()) {
        std::cerr << "file " << fileName << " could not be opened!\n";
        abort();
    }

    file.close();
}
