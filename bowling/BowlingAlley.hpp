#pragma once

#include "Game.hpp"
#include <filesystem>

namespace fs = std::filesystem;

class BowlingAlley : public Game {
public:
    BowlingAlley(fs::path path);
    fs::path getCurrentPath() const;
    void showCurrentPath();
    size_t countFiles();

private:
    fs::path path_;
};