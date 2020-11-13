#pragma once

#include "Frame.hpp"
#include "PlayerData.hpp"

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

class Game {
   public:
    enum class Status {
        NO_GAME,
        IN_PROGRESS,
        FINISHED,
    };

   private:
    std::vector<PlayerData> players{};

    std::vector<Frame> getPlayerRolls(std::ifstream& file);
    std::vector<Frame> getFrames(const std::string& line);
    bool isLastFrame(int frameCount) const;
    bool isStrike(char currentRoll) const;
    bool isSpare(char nextRoll) const;
    Frame getRegularFrame(const std::string& rolls, int currentRoll) const;
    void incrementCharForStrike(int& currentRoll, int frameCount) const;
    void incrementCharForSpare(int& currentRoll, int frameCount) const;

   public:
    Game() = delete;
    Game(const std::filesystem::path& filePath);
    void loadFromFile(const std::string& filePath);
    const std::vector<PlayerData>& getPlayers() const { return players; };
    Status getGameStatus() const;
    std::string getOutputString(int laneNumber) const;
    bool operator==(const Game& rhs) const;
};
