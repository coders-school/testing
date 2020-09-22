#pragma once

#include <iostream>
#include <vector>

#include "DataParser.hpp"
#include "DirectoryHandler.hpp"

class BowlingLane;

class Game {
public:
    Game(const std::string& directoryPath)
        : directoryHandler_(directoryPath) {}

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

private:
    DirectoryHandler directoryHandler_;
    DataParser dataParser_;
    //std::vector<BowlingLane> lanes_;
};
