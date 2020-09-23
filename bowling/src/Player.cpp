#include "../include/Player.hpp"
#include <iostream>

void Player::setScore(int score) {
    score_ = score;
}
void Player::countScore(std::vector<int> points) {
    int score = 0;
    std::vector<std::pair<int, int>> twoThrows;

    for (auto i = 0; i < points.size() - 1; i += 2) {
        twoThrows.push_back(std::make_pair(points[i], points[i + 1]));
    }
    int extraBall = twoThrows.size();
    int throwBalls = 10 < twoThrows.size() ? 10 : twoThrows.size();
    /*
        for (const auto& oneThrow : twoThrows) {
            std::cout << oneThrow.first << " - " << oneThrow.second << "\n";
        }
    */
    for (int i = 0; i < throwBalls; i++) {
        if (twoThrows[i].first == 10 && twoThrows[i + 1].first == 10 && twoThrows.size() > i + 2) {
            score += twoThrows[i].first + twoThrows[i + 1].first + twoThrows[i + 2].first;
        } else if (twoThrows[i].first == 10 && twoThrows[i + 1].first < 10 && twoThrows.size() > i + 1) {
            score += 10 + twoThrows[i + 1].first + twoThrows[i + 1].second;

        } else if (twoThrows[i].first + twoThrows[i].second == 10 && twoThrows.size() > i + 1) {
            score += 10 + twoThrows[i + 1].first;
        } else {
            score += twoThrows[i].first + twoThrows[i].second;
        }
    }

    if (throwBalls < extraBall) {
        score += twoThrows[extraBall].first + twoThrows[extraBall].second;
    }

    Player::setScore(score);
}