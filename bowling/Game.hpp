#pragma once

#include <string>
#include <vector>

struct Frame {
    char firstRoll;
    char secondRoll;
    Frame(char first, char second) : firstRoll(first), secondRoll(second) {}
};

struct PlayerData {
    std::string playerName;
    std::vector<Frame> playerRolls;
};

class Game {
    std::vector<PlayerData> players;
    void fillPlayerName(int& currentCharIndex, std::string& playerName, const std::string& lineText);
    void fillPlayerRolls(int& currentCharIndex,
                         std::vector<Frame>& playerRolls,
                         const std::string& lineText);

   public:
    Game(){};
    void loadFromFile(const std::string& fileName);
    const std::vector<PlayerData>& getPlayers() { return players; };
};
