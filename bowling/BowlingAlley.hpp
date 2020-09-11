#pragma once

#include "Game.hpp"
#include <filesystem>

namespace fs = std::filesystem;

class BowlingAlley : public Game {
public:
    BowlingAlley(fs::path path);
    void showCurrentPath(fs::path path);

private:
    fs::path path_;
};