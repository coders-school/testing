#pragma once

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
class Game;
class BowlingAlley {
public:
    BowlingAlley() = default;
    explicit BowlingAlley(const fs::path& pathToFolder);

    void showCurrentStatus();

private:
    size_t countFiles();
    std::vector<Game*> games_{};
    fs::path path_{};
};
