#pragma once

#include <iostream>
#include <vector>

class Player;

class BowlingLine {
public:

    void printData() {
        std::cout << laneNumber_ << '\n';
        for (const auto& el : players_) {
            //std::cout << el << '\n';
        }
    }

private:
    int laneNumber_;
    std::vector<Player> players_;
};
