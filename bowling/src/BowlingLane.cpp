#include "BowlingLane.hpp"

BowlingLane::GameState BowlingLane::checkGameState(const std::vector<std::shared_ptr<Player>> &players) {
    for(const auto& player : players) {
        if (player->getPoints().size() < 20) {
            return GameState::IN_PROGRESS;
        }
        if (player->getPoints().size() >= 20) {
            return GameState::FINISHED;
        }
        if(player->getPoints().size() <= 0) {
            return GameState::NO_GAME;
        }
    }
    return GameState::NO_GAME;
}

std::string BowlingLane::convertGameState(BowlingLane::GameState gameState) {
    if(gameState == GameState::IN_PROGRESS){
        return "game in progress";
    }
    if(gameState == GameState::FINISHED){
        return "game finished";
    }
    return "no game";
}

std::ostream &operator<<(std::ostream &os, BowlingLane bowlingLane) {
    auto gameState = bowlingLane.checkGameState(bowlingLane.players_);
    os << "### Lane " << bowlingLane.laneNumber_ << ": " << bowlingLane.convertGameState(gameState) << " ###\n";
    for(const auto& player : bowlingLane.players_){
        std::cout << *player;
    }
    std::cout << '\n';
    return os;
}
