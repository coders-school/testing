#include "bowlingGame.hpp"

BowlingGame::BowlingGame(int argc, const char** argv)
    : parser_(argc, argv) {}

bool BowlingGame::isHelpToBePrinted()
{
    return true;
}

void BowlingGame::printHelp()
{
}

void BowlingGame::calculateScores()
{
}

void BowlingGame::outputScores()
{
}

std::string getOutputFileName()
{
    return {};
}

bool isOutputFileGiven()
{
    return true;
}

void showScores()
{
}

void saveScores()
{
}
