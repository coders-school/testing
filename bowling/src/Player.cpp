#include "../include/Player.hpp"
#include <iostream>

int Player::getScore() {
    int score = 0;
    std::vector<std::pair<int, int>> twoThrows;

    for (auto i = 0; i < points_.size() - 1; i += 2) {
        twoThrows.push_back(std::make_pair(points_[i], points_[i + 1]));
    }
    int extraBall = twoThrows.size();
    int throwBalls = 9 < twoThrows.size() ? 9 : twoThrows.size();

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

    for (int i = throwBalls; i < extraBall; i++) {
        score += twoThrows[i].first + twoThrows[i].second;
    }
    return score;
}

std::ostream& operator<<(std::ostream& os, Player player) {
    os << player.name_ << " " << std::to_string(player.getScore()) << '\n';
    return os;
}
