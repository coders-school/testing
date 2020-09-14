#pragma once

#include "Game.hpp"
#include <filesystem>

namespace fs = std::filesystem;

class BowlingAlley : public Game {
public:
    BowlingAlley(fs::path path);
    fs::path getCurrentPath() const;
    void showCurrentPath();

private:
    size_t countFiles();

    fs::path path_;
};
