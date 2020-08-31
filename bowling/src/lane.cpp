#include "lane.hpp"

#include <filesystem>
#include <string>

// private

void Lane::parseFile(std::string fileName) {
    FileHandler file(fileName,Access::INPUT);
    std::string line;
    while(line != "") {
        line = file.readLine();
        gamesInLine_.emplace_back(SingleGame(line));
    } 
}

void Lane::parseLaneName(std::string fileName) {
    std::string fileExtension = std::filesystem::path(fileName).extension();
    std::size_t foundExtensionIndex = fileName.find(fileExtension);

    if (foundExtensionIndex != std::string::npos) {
        fileName.erase(foundExtensionIndex);
    }

    laneName_ = fileName;
}

// public

Lane::Lane(std::string fileName)
{
    parseFile(fileName);
    parseLaneName(fileName);
}

Lane::~Lane() {}

/*std::string Lane::getLaneName()
{
    return laneName_;
}*/

std::ostream& operator<<(std::ostream& os, const Lane& lane)
{
    os << "### " << lane.getLaneName() << ": ";
    std::string playerScore;
    if(lane.gamesInLine_.empty()) {
        os << "no game";
    } else {
        bool finished = true;
        for(auto el : lane.gamesInLine_) {
            if(el.getGameStatus() == SingleGame::GameStatus::IN_PROGRESS) {
                finished = false;
                playerScore << el;
            }
        }
        if(finished) {
            os << "game finished";
        } else {
            os << "game in progress";
        }
    }
    os << " ###\n" << playerScore;
    return os;
}

