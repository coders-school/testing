#include "game.hpp"

#include <iostream>

bool Game::getIsFinished() const {
    return isFinished_;
};

void Game::checkGameProgress(const std::vector<std::pair<int, int>>& score) {
    if (score.size() == 10) {
        isFinished_ = checkEndConditionFor10Turns(score);
    } else if (score.size() == 11) {
        isFinished_ = checkEndConditionFor11Turns(score);
    } else if (score.size() == 12) {
        isFinished_ = checkEndConditionFor12Turns(score);
    } else {
        isFinished_ = false;
    }
};

bool Game::checkEndConditionFor10Turns(const std::vector<std::pair<int, int>>& score) {
    return (score[lastNormalRound].first + score[lastNormalRound].second) < 10;
};

bool Game::checkEndConditionFor11Turns(const std::vector<std::pair<int, int>>& score) {
    return (((score[lastNormalRound].first + score[lastNormalRound].second) == 10) &&
            (score[lastNormalRound].first != 10)) ||
           ((score[lastNormalRound].first == 10) && (score[lastNormalRound + 1].first != 10));
};

bool Game::checkEndConditionFor12Turns(const std::vector<std::pair<int, int>>& score) {
    return (score[lastNormalRound].first == 10) && (score[lastNormalRound + 1].first == 10);
};
