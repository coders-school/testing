#pragma once

#include "Game.hpp"
#include <filesystem>

namespace fs = std::filesystem;

class BowlingAlley : public Game {
public:
    BowlingAlley(fs::path path);
    void showCurrentPath();

private:
    fs::path path_;
};