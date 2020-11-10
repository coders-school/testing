#pragma once

#include "Frame.hpp"

#include <string>
#include <vector>

class PlayerData {
    public:
    std::string name;
    std::vector<Frame> rolls;
    bool operator==(const PlayerData& rhs) const;
};
