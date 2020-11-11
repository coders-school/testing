#pragma once

#include <string>
#include <vector>

#include "game.hpp"

class Player {
public:
    Player();
    Player(std::string name, std::vector<std::pair<int, int>> points);
    std::string getName() const;
    int getScore() const;
    void countScore(std::vector<std::pair<int, int>> points);
    int getPointsSize();
    int getPointsElem(int elem);
    std::string getInfo();
    std::string translateVectorToString();

private:
    std::string name_;
    int score_;
    std::vector<std::pair<int, int>> points_{};
    void setScore(int score);
};
