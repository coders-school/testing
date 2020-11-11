#include "player.hpp"

#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

Player::Player() {}

Player::Player(std::string name, std::vector<std::pair<int, int>> points)
    : name_(name),
      points_(points) {}

std::string Player::getName() const {
    return name_;
}

int Player::getScore() const {
    return score_;
}

void Player::setScore(int score) {
    score_ = score;
}

void Player::countScore(std::vector<std::pair<int, int>> points) {
    int result = 0;
    int lastNormalRound = (9 < points.size() ? 9 : points.size());

    for (auto it = 0; it <= lastNormalRound; it++) {
        if (points[it].first == 10 && points[it + 1].first == 10 && points.size() > it + 2) {
            result += (points[it].first + 10 + points[it + 2].first);
        } else if (points[it].first == 10 && points[it + 1].first < 10 && points.size() > it + 1) {
            result += (points[it].first + points[it + 1].first + points[it + 1].second);
        } else if (points[it].first + points[it].second == 10 && points.size() > it + 1) {
            result += (points[it].first + points[it].second + points[it + 1].first);
        } else if (points[it].first + points[it].second < 10) {
            result += (points[it].first + points[it].second);
        }
    }
    Player::setScore(result);
}

int Player::getPointsSize() {
    return points_.size();
}

int Player::getPointsElem(int elem) {
    return points_.at(elem).first;
}

std::string Player::getInfo() {
    auto ss = std::stringstream{};
    ss << getName()
       << " " << getScore();
    return ss.str();
}

std::string Player::translateVectorToString() {
    std::string stringPoints = name_ + ": ";
    for (const auto& it : points_) {
        if (it.first == 10) {
            stringPoints += "X|";
        } else if (it.first + it.second == 10) {
            stringPoints += it.first;
            stringPoints += "-|";
        } else if (it.first + it.second < 10) {
            stringPoints += it.first;
            stringPoints += it.second;
            stringPoints += "|";
        }
    }
    return stringPoints;
}
