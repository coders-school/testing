#pragma once

#include "Frame.hpp"

#include <string>
#include <vector>

class PlayerData {
    std::string name{};
    std::vector<Frame> rolls{};

    std::vector<Frame> conversionCharNumbersToInt(const std::vector<Frame>& rolls) const;
    size_t countFramesWithoutStrikeOrSpare(const std::vector<Frame>& rolls) const;
    size_t countOnlyStrikeFrames(const std::vector<Frame>& rolls) const;
    size_t countOnlySpareFrames(const std::vector<Frame>& rolls) const;
    bool isBadCharacter(char) const;

   public:
    PlayerData() = default;
    PlayerData(const std::string& n, const std::vector<Frame>& r);
    bool operator==(const PlayerData& rhs) const;
    size_t countPoints() const;
    const std::vector<Frame>& getRolls() const;
    const std::string& getName() const;
};
