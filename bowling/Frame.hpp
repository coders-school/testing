#pragma once

#include <ostream>

class Frame {
    char firstRoll{' '};
    char secondRoll{' '};

   public:
    Frame() = default;
    Frame(char first, char second);
    bool operator==(const Frame& rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Frame& frame);
    char getFirstRoll() const;
    char getSecondRoll() const;
    bool isSpare() const;
    bool isStrike() const;
};


