#include "BowlingAlley.hpp"
#include <iostream>

BowlingAlley::BowlingAlley(std::filesystem::path path)
    : path_(path) 
    {}

void BowlingAlley::showCurrentPath(std::filesystem::path path) {
    std::cout << "Your current path is: " << std::filesystem::current_path() << 'n';
}
