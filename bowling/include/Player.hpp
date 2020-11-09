#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name, const std::vector<int>& points)
        : name_{name}, points_{points} {}
    Player() {}
    std::string getName() const { return name_; }
    size_t getGameSize() const { return points_.size(); }
    int getScore();
    std::vector<int> getPoints() const { return points_; }
    friend std::ostream& operator<<(std::ostream& os, Player player);

private:
    std::string name_;
    std::vector<int> points_;
};
