#pragma once

#include <memory>
#include <string>
#include <vector>

#include "file.hpp"
#include "player.hpp"

enum class gameStatus {
    NoGame,
    InProgress,
    Finish
};

class BowlingLane {
public:
    BowlingLane(std::vector<std::unique_ptr<Player>> players);
    void setPlayer(std::string name, std::vector<std::pair<int, int>> points);
    void printResultToScreen();
    bool checkGameStatus();
    gameStatus getGameStatus();
    std::string convertEnumToString();
    std::string getResult();

private:
    gameStatus status_;
    std::string name_;
    std::unique_ptr<File> file_;
    std::vector<std::unique_ptr<Player>> players_;
};
