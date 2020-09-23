#pragma once

#include <iostream>
#include <vector>

#include "BowlingLane.hpp"
#include "DataParser.hpp"
#include "DirectoryHandler.hpp"

class Game {
public:
    Game(const std::string& directoryPath)
        : directoryHandler_(directoryPath) {
        processData();
    }

    void printInputData() {
        //test purpose function
        std::map<int, std::vector<std::string>> testLanes = directoryHandler_.getDirectoryData();
        for (auto lane : testLanes) {
            std::cout << "Lane " << lane.first << '\n';
            for (auto player : lane.second) {
                std::cout << '\t' << player << '\n';
            }
        }
    }

    void printResults() {
        for (auto el : lanes_) {
            el->printData();
        }
    }

private:
    DirectoryHandler directoryHandler_;
    DataParser dataParser_;
    std::vector<std::shared_ptr<BowlingLane>> lanes_;

    void processData() {
        auto parser = std::make_shared<DataParser>();
        std::map<int, std::vector<std::string>> rawLanes = directoryHandler_.getDirectoryData();
        for (auto lane : rawLanes) {
            auto laneNumber = lane.first;
            std::vector<std::shared_ptr<Player>> players;
            for (auto player : lane.second) {
                auto playerData = parser->dataParsing(player);
                players.emplace_back(std::make_shared<Player>(playerData.first, playerData.second));
            }
            lanes_.emplace_back(std::make_shared<BowlingLane>(laneNumber, players));
        }
    }
};
