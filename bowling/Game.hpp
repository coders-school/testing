#pragma once

#include <string>
#include <vector>

struct Frame {
    char firstRoll;
    char secondRoll;
    Frame(char first, char second) : firstRoll(first), secondRoll(second) {}
};

struct PlayerData {
    std::string Name;
    std::vector<Frame> Rolls;
};

class Game {
    std::vector<PlayerData> players;
    void loadPlayerRolls(std::fstream& file,
                         std::vector<Frame>& playerRolls);

   public:
    Game(){};
    void loadFromFile(const std::string& fileName);
    const std::vector<PlayerData>& getPlayers() { return players; };
};
