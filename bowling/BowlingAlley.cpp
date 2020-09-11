#include "BowlingAlley.hpp"
#include <iostream>

BowlingAlley::BowlingAlley(fs::path path)
    : path_(path) 
    {}

void BowlingAlley::showCurrentPath(fs::path path) {
    std::cout << "Your current path is: " << fs::current_path() << 'n';
}
