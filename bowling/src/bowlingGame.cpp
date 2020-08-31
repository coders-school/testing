#include "bowlingGame.hpp"

#include <algorithm>
#include <iostream>

BowlingGame::BowlingGame(int argc, const char** argv)
    : parser_(argc, argv) {}

bool BowlingGame::isHelpToBePrinted() {
    const std::vector<std::string> printHelpParams{"-h", "--help"};

    return std::any_of(printHelpParams.cbegin(), printHelpParams.cend(),
                       [this](auto& helpParam) {
                           return parser_.checkIfArgumentExists(helpParam);
                       });
}

namespace {
std::string helpMessage =
    "Search for help in documentation of our repository, have fun!!";
}

std::string& BowlingGame::printHelp() const {
    return helpMessage;
}

void BowlingGame::calculateScores() {
}

void BowlingGame::outputScores() {
}

std::string getOutputFileName() {
    return {};
}

bool isOutputFileGiven() {
    return true;
}

void showScores() {
}

void saveScores() {
}
