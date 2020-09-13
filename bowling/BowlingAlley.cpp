#include "BowlingAlley.hpp"
#include <iostream>

namespace fs = std::filesystem;

BowlingAlley::BowlingAlley(fs::path path)
    : path_(path) 
    {}

fs::path BowlingAlley::getCurrentPath() const {
    return path_;
}

void BowlingAlley::showCurrentPath() {
    std::cout << "Your current path is: " << fs::current_path() << 'n';
}
