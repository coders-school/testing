#include "BowlingLane.hpp"

BowlingLane::GameState BowlingLane::checkGameState() {
    for (const auto& player : players_) {
        if (player->getPoints().size() < 20) {
            return GameState::IN_PROGRESS;
        }
        if (player->getPoints().size() >= 20) {
            return GameState::FINISHED;
        }
        if (player->getPoints().size() <= 0) {
            return GameState::NO_GAME;
        }
    }
    return GameState::NO_GAME;
}

std::string BowlingLane::convertGameState(BowlingLane::GameState gameState) {
    return gameStateMap_.at(gameState);
}

std::ostream& operator<<(std::ostream& os, BowlingLane bowlingLane) {
    auto gameState = bowlingLane.checkGameState();
    os << "### Lane " << bowlingLane.laneNumber_ << ": " << bowlingLane.convertGameState(gameState) << " ###\n";
    for (const auto& player : bowlingLane.players_) {
        std::cout << *player;
    }
    std::cout << '\n';
    return os;
}
