#pragma once

#include "argumentParser.hpp"
#include "directoryHandler.hpp"
#include "fileHandler.hpp"
#include "lane.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>

class BowlingGameStub {
public:
    BowlingGameStub(int argc, const char** argv);
    BowlingGameStub() = delete;

    bool isHelpToBePrinted();
    std::string& printHelp() const;

    void calculateScores();
    void outputScores();

    std::stringstream showScores();
    std::stringstream saveScores();
    
private:
    ArgumentParser parser_;
    std::vector<Lane> lanes_;

    std::string getOutputFileName();
    bool isOutputFileGiven();
    bool isInputDirectoryGiven();
};

BowlingGameStub::BowlingGameStub(int argc, const char** argv)
    : parser_(argc, argv) {}

bool BowlingGameStub::isHelpToBePrinted()
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
    "BowlingGameStub <input directory> <output file>\n\
This program can be used to calculate scores of the bowling game. It program takes two arguments :\n\
\t<input directory> - input directory containing files with the games states on lanes\n\
\t<output file> - optional, output file where scores can be stored. By default scores are printed on the screen.\n\n\
BowlingGameStub -h or BowlingGameStub --help\n\
\tprints this help\n\n";
}

std::string& BowlingGameStub::printHelp() const
{
    return helpMessage;
}

void BowlingGameStub::calculateScores()
{
    if (isInputDirectoryGiven()) {
        DirectoryHandler dirHandler{parser_.getArgument(ArgumentParser::ArgumentNumber::FIRST_ARGUMENT)};
        for (auto& fileInDirectory : dirHandler.getFilesInDirectory()) {
            lanes_.emplace_back(fileInDirectory);
        }
    }
}

void BowlingGameStub::outputScores()
{
    if (isInputDirectoryGiven()) {
        showScores();

        if (isOutputFileGiven()) {
            saveScores();
        }
    }
}

std::string BowlingGameStub::getOutputFileName()
{
    if (isOutputFileGiven()) {
        return parser_.getArgument(ArgumentParser::ArgumentNumber::SECOND_ARGUMENT);
    }
    return {};
}

bool BowlingGameStub::isOutputFileGiven()
{
    return !isHelpToBePrinted() && parser_.getArgumentsNumber() == 2;
}

bool BowlingGameStub::isInputDirectoryGiven()
{
    return !isHelpToBePrinted() &&
           (parser_.getArgumentsNumber() == 1 || parser_.getArgumentsNumber() == 2);
}

std::stringstream BowlingGameStub::showScores()
{
    std::stringstream ss;
    for (auto& lane : lanes_) {
        ss << lane << '\n';
    }
    return ss;
}

std::stringstream BowlingGameStub::saveScores()
{
    std::stringstream ss;
    for (auto& lane : lanes_) {
        ss << lane << '\n';
    }
    return ss;
}
