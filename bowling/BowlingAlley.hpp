#pragma once

#include <filesystem>
#include <memory>
#include <vector>

namespace fs = std::filesystem;
class Game;
class BowlingAlley {
public:
    BowlingAlley() = default;
    explicit BowlingAlley(const fs::path& pathToFolder);
    void loadFromFolder(const fs::path& pathToFolder);

private:
    std::vector<std::shared_ptr<Game>> games_{};
    fs::path path_{};
};
