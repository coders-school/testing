#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Frame {
    char firstRoll;
    char secondRoll;
    Frame() : firstRoll(' '), secondRoll(' ') {}
    Frame(char first, char second) : firstRoll(first), secondRoll(second) {}
    bool operator==(const Frame& rhs) const { return firstRoll == rhs.firstRoll && secondRoll == rhs.secondRoll; }
};

inline std::ostream& operator<<(std::ostream& os, const Frame& frame) {
    os << "{" << frame.firstRoll << ", " << frame.secondRoll << "}";
    return os;
}

struct PlayerData {
    std::string name;
    std::vector<Frame> rolls;
};

class Game {
    std::vector<PlayerData> players;
    void loadPlayerRolls(std::ifstream& file, std::vector<Frame>& playerRolls);
    bool isLastFrame(int frameCount);
    bool isStrike(char currentRoll);
    bool isSpare(char nextRoll);

   public:
    Game(){};
    void loadFromFile(const std::string& fileName);
    const std::vector<PlayerData>& getPlayers() { return players; };
};
