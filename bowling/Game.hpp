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

    void loadPlayerRolls(std::ifstream& file, std::vector<Frame>& playerRolls);
    bool isLastFrame(int frameCount) const;
    bool isStrike(char currentRoll) const;
    bool isSpare(char nextRoll) const;
    Frame getRegularFrame(const std::string& rolls, int currentRoll) const;
    void incrementStrikeCounters(int& currentRoll, int frameCount) const;
    void incrementSpareCounters(int& currentRoll, int frameCount) const;

   public:
    Game() = default;
    Game(const std::filesystem::path& filePath);
    void loadFromFile(const std::string& filePath);
    const std::vector<PlayerData>& getPlayers() const { return players; };
    Status getGameStatus() const;
    std::string getOutputString(int laneNumber) const;
    bool operator==(const Game& rhs) const;
};
