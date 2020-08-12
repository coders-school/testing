#pragma once

#include <vector>
class Game {
    public:

    int getScore() const {
        return 0;
    }

    void roll(int point){
        rolls_.push_back(point);
    }

private:
    std::vector<int> rolls_;
};
