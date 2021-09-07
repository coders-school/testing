#include "Score.hpp"
#include <iostream>

void Score::addResult(size_t throwResult) {
    if(throwResult > 10) {
        throw std::invalid_argument("Score::addResult invalid argument");
    }
    if (frameEnd_ == false) {
        result_[currentFrame_].first = static_cast<uint8_t>(throwResult);
        frameEnd_ = true;
    } else {
        result_[currentFrame_].second = static_cast<uint8_t>(throwResult);
        frameEnd_ = false;
        ++currentFrame_;
    }
}

uint16_t Score::getScore() {
    return 0;
}

std::string Score::resultsToString() {
    std::string str;
    for (uint8_t ture = 0; ture < currentFrame_; ++ture) {
        if (ture == bonusTurn_) {
            if (result_[bonusTurn_ - 1].first + result_[bonusTurn_ - 1].second != maxOneThrowPoints_) {
                return str;
            } else if (result_[bonusTurn_ - 1].first == maxOneThrowPoints_) {
                    str += throwResultToString(bonusTurn_, 1) + throwResultToString(bonusTurn_, 2);
                    return str;
                }
            else {
                str += throwResultToString(bonusTurn_, 1);
                return str;
            }
        }
        str += throwResultToString(ture, 1);
        if (result_[ture].first != maxOneThrowPoints_) {
                str += throwResultToString(ture, 2);
        }
        if (ture == bonusTurn_ - 1) {
            str += "||";
        } else if (ture < bonusTurn_) {
            str += '|';
        }
        for (uint8_t ture = currentFrame_; ture < result_.size(); ++ture) {
            str += "  ";
            if (ture == bonusTurn_ - 1) {
                str += "||";
            } else if (ture < bonusTurn_ - 1) {
                str += '|';
            }
        }
    }
    return str;
}

std::string Score::throwResultToString(uint8_t ture, uint8_t throwInTurn) {
    if (throwInTurn == 1) {
        if (result_[ture].first == maxOneThrowPoints_) {
            return "X";
        } else if (result_[ture].first == 0) {
            return "-";
        } else {
            return std::to_string(result_[ture].first);
        }
    } else {
        if (result_[ture].second == maxOneThrowPoints_ && ture == bonusTurn_) {
            return "X";
        }
        if (result_[ture].second == maxOneThrowPoints_) {
            return "/";
        }
        if (result_[ture].first + result_[ture].second == maxOneThrowPoints_) {
            return "/";
        }
        if (result_[ture].second == 0) {
            return "-";
        }
        return std::to_string(result_[ture].second);
    }
}
