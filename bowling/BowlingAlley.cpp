#include "BowlingAlley.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "Game.hpp"

namespace fs = std::filesystem;

BowlingAlley::BowlingAlley(const fs::path& pathToFolder)
:path_(pathToFolder)
{
    loadFromFolder(path_);
}

void BowlingAlley::showCurrentStatus() {
    std::cout << "Your current path is: " << path_ << '\n'
              << "I found " << countFiles() << " file(s) here. \n";
}

size_t BowlingAlley::countFiles() {
    size_t fileCounter = 0;
    fileCounter = std::distance(fs::directory_iterator(path_), fs::directory_iterator{});
    return fileCounter;
}

void BowlingAlley::loadFromFolder(const fs::path& pathToFolder) {
    if (!fs::is_directory(pathToFolder)) {
        throw std::logic_error{"please enter path to directory!\n"};
    }
    for (auto& entry : fs::directory_iterator(pathToFolder)) {
        if (entry.is_regular_file()) {
            games_.emplace_back(std::make_shared<Game>(entry.path()));
        }
    }
}

void BowlingAlley::printOutputTo(std::ostream& os) {
    for (size_t gameNumber = 0; gameNumber < games_.size(); gameNumber++) {
        games_[gameNumber]->printOutput(os, gameNumber + 1);
    }
}
