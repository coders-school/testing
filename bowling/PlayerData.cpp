#include "PlayerData.hpp"

bool PlayerData::operator==(const PlayerData& rhs) const {
    return name == rhs.name && rolls == rhs.rolls;
}
