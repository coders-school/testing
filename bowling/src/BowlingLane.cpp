#include "BowlingLane.hpp"

#include <algorithm>

BowlingLane::GameState BowlingLane::checkGameState() {
    if (std::any_of(players_.begin(), players_.end(),
                    [](const auto& player) { return player->getGameSize() < 20; })) {
        return GameState::IN_PROGRESS;
    }
    if (std::any_of(players_.begin(), players_.end(),
                    [](const auto& player) { return player->getGameSize() >= 20; })) {
        return GameState::FINISHED;
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
        os << *player;
    }
    return os;
}
