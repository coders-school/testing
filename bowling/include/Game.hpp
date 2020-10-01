#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "BowlingLane.hpp"
#include "DataParser.hpp"
#include "DirectoryHandler.hpp"

class Game {
public:
    Game(const std::string& directoryPath, const std::string& resultOutput = "")
        : directoryHandler_(directoryPath), resultOutput_(resultOutput) {
        processData();
    }

    std::vector<std::shared_ptr<BowlingLane>> getLanes() const { return lanes_; }
    void printResult();
    void saveDataToFile();

private:
    DirectoryHandler directoryHandler_;
    std::vector<std::shared_ptr<BowlingLane>> lanes_;
    std::string resultOutput_;
    void processData();
};
