#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class BowlingAlley {
public:
    explicit BowlingAlley(const fs::path& pathToFolder);
    void showCurrentStatus();

private:
    size_t countFiles();

    fs::path path_;
};
