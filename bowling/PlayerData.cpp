#include "PlayerData.hpp"

#include <algorithm>

PlayerData::PlayerData(const std::string& n, const std::vector<Frame>& r) : name(n), rolls(r) {
}

bool PlayerData::operator==(const PlayerData& rhs) const {
    return name == rhs.name && rolls == rhs.rolls;
}

const std::vector<Frame>& PlayerData::getRolls() const {
    return rolls;
}

const std::string& PlayerData::getName() const {
    return name;
}

size_t PlayerData::countFramesWithoutStrikeOrSpare(const std::vector<Frame>& rolls) const {
    size_t totalPointsWithoutStrikeNorSpare = 0;
    for (size_t i = 0; i < rolls.size(); i++) {
        if (!rolls[i].isStrike() && !rolls[i].isSpare()) {
            totalPointsWithoutStrikeNorSpare += (rolls[i].getFirstRoll() + rolls[i].getSecondRoll());
        }
    }
    return totalPointsWithoutStrikeNorSpare;
}

size_t PlayerData::countOnlyStrikeFrames(const std::vector<Frame>& rolls) const {
    size_t totalOnlyStrikePoints = 0;
    for (size_t i = 0; i < rolls.size(); i++) {
        if (rolls[i].isStrike()) {
            totalOnlyStrikePoints += 10;
            if ((i + 1) != rolls.size()) {
                if (rolls.at(i + 1).isStrike() || rolls.at(i + 1).isSpare()) {
                    totalOnlyStrikePoints += 10;
                } else {
                    totalOnlyStrikePoints += (rolls[i + 1].getFirstRoll() + rolls[i + 1].getSecondRoll());
                }
            }
        }
    }
    return totalOnlyStrikePoints;
}

size_t PlayerData::countOnlySpareFrames(const std::vector<Frame>& rolls) const {
    size_t totalOnlySparePoints = 0;
    for (size_t i = 0; i < rolls.size(); i++) {
        if (rolls[i].isSpare()) {
            totalOnlySparePoints += 10;
            if ((i + 1) != rolls.size()) {
                if (rolls.at(i + 1).isStrike()) {
                    totalOnlySparePoints += 10;
                } else {
                    totalOnlySparePoints += rolls[i + 1].getFirstRoll();
                }
            }
        }
    }
    return totalOnlySparePoints;
}

size_t PlayerData::countPoints() const {
    size_t totalPoints = 0;
    auto convertedRolls = conversionCharNumbersToInt(rolls);
    totalPoints += countFramesWithoutStrikeOrSpare(convertedRolls);
    totalPoints += countOnlyStrikeFrames(convertedRolls);
    totalPoints += countOnlySpareFrames(convertedRolls);
    return totalPoints;
}

std::vector<Frame> PlayerData::conversionCharNumbersToInt(const std::vector<Frame>& rolls) const {
    std::vector<Frame> convertedRolls{};
    Frame currentFrame{};
    char conversionNumber = '0';
    size_t firstRoll{};
    size_t secondRoll{};
    for (size_t i = 0; i < rolls.size(); i++) {
        firstRoll = rolls[i].getFirstRoll();
        secondRoll = rolls[i].getSecondRoll();
        if (!rolls[i].isStrike() && !rolls[i].isSpare()) {
            firstRoll = (rolls[i].getFirstRoll() - conversionNumber);
            secondRoll = (rolls[i].getSecondRoll() - conversionNumber);
        }
        if (rolls[i].isSpare()) {
            firstRoll = (rolls[i].getFirstRoll() - conversionNumber);
        }
        if (isBadCharacter(rolls[i].getFirstRoll())) {
            firstRoll = 0;
        }
        if (isBadCharacter(rolls[i].getSecondRoll())) {
            secondRoll = 0;
        }
        currentFrame = (Frame(firstRoll, secondRoll));
        convertedRolls.push_back(currentFrame);
    }
    return convertedRolls;
}

bool PlayerData::isBadCharacter(char roll) const {
    constexpr char badCharacters[]{'-', ' ', '\0'};
    return std::any_of(std::begin(badCharacters), std::end(badCharacters), [roll](char bad) { return roll == bad; });
}
