#pragma once

#include "Player.hpp"

#include <iostream>
#include <vector>

class Player;

class BowlingLine {
public:
    BowlingLine(const int laneNumber, const std::vector<std::shared_ptr<Player>>& players)
        : laneNumber_(laneNumber), players_(players) {}

    void printData() {
        std::cout << laneNumber_ << '\n';
        // for (const auto& el : players_) {
        //     //std::cout << el << '\n';
        // }
    }

private:
    int laneNumber_;
    std::vector<std::shared_ptr<Player>> players_;
};
