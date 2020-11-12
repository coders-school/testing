#include "Frame.hpp"

Frame::Frame(char first, char second) : firstRoll(first), secondRoll(second) {
}

bool Frame::operator==(const Frame& rhs) const {
    return firstRoll == rhs.firstRoll && secondRoll == rhs.secondRoll;
}

char Frame::getFirstRoll() const { return firstRoll; };

char Frame::getSecondRoll() const { return secondRoll; };

std::ostream& operator<<(std::ostream& os, const Frame& frame) {
    os << "{" << frame.firstRoll << ", " << frame.secondRoll << "}";
    return os;
}

bool Frame::isSpare() const {
    return secondRoll == '/';
}

bool Frame::isStrike() const {
    return firstRoll == 'X';
}
