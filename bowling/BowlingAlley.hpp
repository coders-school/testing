#pragma once

#include "Game.hpp"
#include <filesystem>

namespace fs = std::filesystem;

class BowlingAlley : public Game {
public:
    BowlingAlley(fs::path path);
    void showCurrentStatus();

private:
    size_t countFiles();

    fs::path path_;
};
