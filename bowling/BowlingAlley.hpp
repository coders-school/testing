#pragma once

#include "Game.hpp"
#include <filesystem>

class BowlingAlley : public Game {
public:
    BowlingAlley(std::filesystem::path path);

private:
    std::filesystem::path path_;
};