#include "BowlingAlley.hpp"
#include <algorithm>
#include <iostream>

namespace fs = std::filesystem;

BowlingAlley::BowlingAlley(fs::path path)
    : path_(path) 
    {}

fs::path BowlingAlley::getCurrentPath() const {
    return path_;
}

void BowlingAlley::showCurrentPath() {
    std::cout << "Your current path is: " << path_ << 'n';
}

size_t BowlingAlley::countFiles() {
    size_t fileCounter = 0;
    fileCounter = std::distance(fs::directory_iterator(path_), fs::directory_iterator{});
    return fileCounter;
}
