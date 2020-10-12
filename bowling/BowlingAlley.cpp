#include "BowlingAlley.hpp"
#include <algorithm>
#include <iostream>

namespace fs = std::filesystem;

BowlingAlley::BowlingAlley(const fs::path& pathToFolder)
:path_(pathToFolder)
{
    
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
