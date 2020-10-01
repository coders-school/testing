#include "Game.hpp"

void Game::printResult() {
    for (const auto& lane : lanes_) {
        std::cout << *lane;
    }
}

void Game::saveDataToFile() {
    if (resultOutput_ != "") {
        std::ofstream result(resultOutput_, std::ios_base::out);
        if (result.is_open()) {
            for (const auto& lane : lanes_) {
                result << *lane;
            }
            result.close();
        } else {
            std::cout << "Cannot open file\n";
        }
    } else {
        std::cout << "Cannot save to file - no argument provided\n";
    }
}

void Game::processData() {
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
