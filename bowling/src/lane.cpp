#include "lane.hpp"

#include <filesystem>
#include <string>

// private

void Lane::parseFile(std::string fileName)
{
    FileHandler file(fileName, Access::INPUT);
    std::string line = file.readLine();
    while (!line.empty()) {
        gamesInLine_.emplace_back(SingleGame(line));
        line = file.readLine();
    }
}

void Lane::parseLaneName(std::string fileName)
{
    laneName_ = std::filesystem::path(fileName).filename().stem();
}

// public

Lane::Lane(std::string fileName)
{
    parseFile(fileName);
    parseLaneName(fileName);
}

Lane::~Lane() {}

std::ostream& operator<<(std::ostream& os, const Lane& lane)
{
    os << "### " << lane.getLaneName() << ": ";
    if (lane.gamesInLine_.empty()) {
        os << "no game ###\n";
    }
    else {
        bool finished = true;
        for (auto el : lane.gamesInLine_) {
            if (el.getGameStatus() == SingleGame::GameStatus::IN_PROGRESS) {
                finished = false;
            }
        }
        if (finished) {
            os << "game finished ###\n";
        }
        else {
            os << "game in progress ###\n";
        }
        for (auto el : lane.gamesInLine_) {
            os << el;
        }
    }
    return os;
}
