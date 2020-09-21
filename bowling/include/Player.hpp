#pragma once

#include <string>
#include <vector>

class Player {
public:

    Player(const std::string& name, const std::vector<int>& points)
        : name_{name}, points_{points} {}

    std::string getName() const {
        return name_;
    }

    int getScore() {
        return 0;
    }

private:
    std::string name_;
    std::vector<int> points_;
};
