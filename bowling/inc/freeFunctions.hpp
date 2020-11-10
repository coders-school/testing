#pragma once
#include <string>

namespace {
std::string helpMessage =
    "BowlingGame <input directory> <output file>\n\
This program can be used to calculate scores of the bowling game. It program takes two arguments :\n\
\t<input directory> - input directory containing files with the games states on lanes\n\
\t<output file> - optional, output file where scores can be stored. By default scores are printed on the screen.\n\n\
BowlingGame -h or BowlingGame --help\n\
\tprints this help\n\n";
}

std::string& printHelp();