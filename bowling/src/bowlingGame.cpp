#include "bowlingGame.hpp"

#include "directoryHandler.hpp"
#include "fileHandler.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

BowlingGame::BowlingGame(int argc, const char** argv)
    : parser_(argc, argv) {}

bool BowlingGame::isHelpToBePrinted()
{
    const std::vector<std::string> printHelpParams{"-h", "--help"};

    return (parser_.getArgumentsNumber() == 1) &&
           std::any_of(printHelpParams.cbegin(), printHelpParams.cend(),
                       [this](auto& helpParam) {
                           return parser_.checkIfArgumentExists(helpParam);
                       });
}

namespace {
std::string helpMessage =
    "BowlingGame <input directory> <output file>\n\
This program can be used to calculate scores of the bowling game. It program takes two arguments :\n\
\t<input directory> - input directory containing files with the games states on lanes\n\
\t<output file> - optional, output file where scores can be stored. By default scores are printed on the screen.\n\n\
BowlingGame -h or BowlingGame --help\n\
\tprints this help\n\n";
}

std::string& BowlingGame::printHelp() const
{
    return helpMessage;
}

void BowlingGame::calculateScores()
{
    if (isInputDirectoryGiven()) {
        DirectoryHandler dirHandler{parser_.getArgument(ArgumentParser::ArgumentNumber::FIRST_ARGUMENT)};
        for (auto& fileInDirectory : dirHandler.getFilesInDirectory()) {
            lanes_.emplace_back(fileInDirectory);
        }
    }
}

void BowlingGame::outputScores()
{
    if (isInputDirectoryGiven()) {
        showScores();

        if (isOutputFileGiven()) {
            saveScores();
        }
    }
}

std::string BowlingGame::getOutputFileName()
{
    if (isOutputFileGiven()) {
        return parser_.getArgument(ArgumentParser::ArgumentNumber::SECOND_ARGUMENT);
    }
    return {};
}

bool BowlingGame::isOutputFileGiven()
{
    return !isHelpToBePrinted() && parser_.getArgumentsNumber() == 2;
}

bool BowlingGame::isInputDirectoryGiven()
{
    return !isHelpToBePrinted() &&
           (parser_.getArgumentsNumber() == 1 || parser_.getArgumentsNumber() == 2);
}

void BowlingGame::showScores()
{
    for (auto& lane : lanes_) {
        std::cout << lane << '\n';
    }
}

void BowlingGame::saveScores()
{
    FileHandler outputFile{getOutputFileName(), FileHandler::FileAccess::OUTPUT};
    for (auto& lane : lanes_) {
        std::stringstream ss;
        ss << lane << '\n';
        outputFile.write(ss.str());
    }
}
