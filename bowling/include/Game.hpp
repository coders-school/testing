#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "BowlingLane.hpp"
#include "DataParser.hpp"
#include "DirectoryHandler.hpp"


class Game {
public:
    Game(const std::string& directoryPath)
        : directoryHandler_(directoryPath) {
        processData();
    }

//    void printInputData() {
//        //test purpose function
//        std::map<int, std::vector<std::string>> testLanes = directoryHandler_.getDirectoryData();
//        for (auto lane : testLanes) {
//            std::cout << "Lane " << lane.first << '\n';
//            for (auto player : lane.second) {
//                std::cout << '\t' << player << '\n';
//            }
//        }
//    }

    void printResult() {
        for(const auto& lane : lanes_){
            std::cout << *lane;
        }
    }

    void saveDataToFile(){
        std::ofstream result("../result.txt", std::ios_base::out);
        if(result.is_open()){
            for(const auto& lane : lanes_){
                auto laneNumber = lane->getLaneNumber();
                auto gamesState = lane->convertGameState(lane->checkGameState());

                result << "### Lane: " << laneNumber << ": " << gamesState << " ###\n";
                for(const auto& player : lane->getPlayers()){
                    result << player->getName() << " " << std::to_string(player->getScore()) << "\n";
                }
                result << "\n";
            }
            result.close();
        }
        else{
            std::cout << "Cannot open file\n";
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
