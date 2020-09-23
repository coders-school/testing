#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Player.hpp"

class BowlingLane {
public:
    BowlingLane(const int laneNumber, const std::vector<std::shared_ptr<Player>>& players)
        : laneNumber_(laneNumber), players_(players) {}

    void printData() {
        std::cout <<"Lane number "<< laneNumber_ << '\n';
        for (const auto& el : players_) {
            std::cout << el->getName() << "\t" << el->getScore() << '\n';
        }
    }

private:
    int laneNumber_;
    std::vector<std::shared_ptr<Player>> players_;
};
