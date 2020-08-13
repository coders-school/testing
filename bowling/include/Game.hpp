#pragma once

#include <vector>
#include <numeric>
class Game {
    public:

    int getScore() const {
        return std::accumulate(rolls_.begin(), rolls_.end(), 0);
    }

    void roll(int point){
        rolls_.push_back(point);
    }

private:
    std::vector<int> rolls_;
};
