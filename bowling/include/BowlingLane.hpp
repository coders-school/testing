#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include "Player.hpp"

class BowlingLane {
public:
    enum class GameState{
        FINISHED = 1,
        IN_PROGRESS,
        NO_GAME
    };

    std::vector<std::shared_ptr<Player>> getPlayers() const { return players_; }
    int getLaneNumber() const { return laneNumber_; }

    BowlingLane(const int laneNumber, const std::vector<std::shared_ptr<Player>>& players)
        : laneNumber_(laneNumber), players_(players) {}

    GameState checkGameState(const std::vector<std::shared_ptr<Player>>& players);

    std::string convertGameState(GameState gameState);

    friend std::ostream& operator<<(std::ostream& os, BowlingLane bowlingLane);

private:
//    std::map<GameState, std::string> gameStateMap_{
//            {GameState::FINISHED,    "game finished"},
//            {GameState::IN_PROGRESS, "game in progress"},
//            {GameState::NO_GAME,     "no game"}
//    };
    int laneNumber_;
    std::vector<std::shared_ptr<Player>> players_;
};
