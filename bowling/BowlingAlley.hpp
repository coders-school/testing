#pragma once

#include <filesystem>
#include <memory>
#include <vector>

class Game;
class BowlingAlley {
public:
    BowlingAlley() = default;
    explicit BowlingAlley(const std::filesystem::path& pathToFolder);
    void loadFromFolder(const std::filesystem::path& pathToFolder);
    std::string getOutputString();

private:
    std::vector<std::shared_ptr<Game>> games_{};
    std::filesystem::path path_{};
};
