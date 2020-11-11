#pragma once

#include <vector>

constexpr int lastNormalRound = 9;

class Game {
public:
    void checkGameProgress(const std::vector<std::pair<int, int>>& score);
    bool getIsFinished() const;

private:
    bool isFinished_;
    bool checkEndConditionFor10Turns(const std::vector<std::pair<int, int>>& score);
    bool checkEndConditionFor11Turns(const std::vector<std::pair<int, int>>& score);
    bool checkEndConditionFor12Turns(const std::vector<std::pair<int, int>>& score);
};
