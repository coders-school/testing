#pragma once

#include "fileHandler.hpp"
#include "singleGame.hpp"

#include <iostream>
#include <string>
#include <vector>

using Access = FileHandler::FileAccess;

class Lane {
private:
    std::vector<SingleGame> gamesInLine_{};
    std::string laneName_{};

    void parseFile(std::string fileName);
    void parseLaneName(std::string laneName);

public:
    explicit Lane(std::string fileName);
    Lane() = delete;
    ~Lane();

    std::string getLaneName() const { return laneName_; };
    friend std::ostream& operator<<(std::ostream& os, const Lane& lane);
};
