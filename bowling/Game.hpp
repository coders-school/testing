#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

class Frame {
    char firstRoll;
    char secondRoll;

   public:
    Frame() : firstRoll(' '), secondRoll(' ') {}
    Frame(char first, char second) : firstRoll(first), secondRoll(second) {}
    bool operator==(const Frame& rhs) const { return firstRoll == rhs.firstRoll && secondRoll == rhs.secondRoll; }
    friend std::ostream& operator<<(std::ostream& os, const Frame& frame);
    char getFirstRoll() const { return firstRoll; };
    char getSecondRoll() const { return secondRoll; };
};

inline std::ostream& operator<<(std::ostream& os, const Frame& frame) {
    os << "{" << frame.firstRoll << ", " << frame.secondRoll << "}";
    return os;
}

class Game {
   public:
    enum class Status {
        NO_GAME,
        IN_PROGRESS,
        FINISHED,
    };

   private:
    struct PlayerData {
        std::string name;
        std::vector<Frame> rolls;
    };
    std::vector<PlayerData> players{};

    void loadPlayerRolls(std::ifstream& file, std::vector<Frame>& playerRolls);
    bool isLastFrame(int frameCount) const;
    bool isStrike(char currentRoll) const;
    bool isStrike(const Frame& frame) const;
    bool isSpare(char nextRoll) const;
    bool isSpare(const Frame& frame) const;
    bool isBadCharacter(char) const;
    std::vector<Frame> conversionCharNumbersToInt(const std::vector <Frame>& rolls) const;
    size_t countFramesWithoutStrikeOrSpare(const std::vector<Frame>& rolls) const;
    size_t countOnlyStrikeFrames(const std::vector<Frame>& rolls) const;
    size_t countOnlySpareFrames(const std::vector<Frame>& rolls) const;
    std::string getOutputString(int laneNumber) const;

   public:
    Game() = default;
    Game(const std::filesystem::path& filePath);
    void loadFromFile(const std::string& filePath);
    const std::vector<PlayerData>& getPlayers() const { return players; };
    size_t countPoints(const std::vector<Frame>& rolls) const;
    Status getGameStatus() const;
    void printOutput(std::ostream& os, int laneNumber) const;
};
