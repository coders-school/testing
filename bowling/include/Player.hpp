#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name, const std::vector<int>& points) : name_{name}, points_{points} {}
    Player() {}
    std::string getName() const { return name_; }

    int countScore(std::vector<int> points);

private:
    std::string name_;
    std::vector<int> points_;
};
