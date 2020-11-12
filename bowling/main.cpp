#include <fstream>
#include <iostream>
#include <string>

#include <algorithm>
#include <cstring>
#include "BowlingAlley.hpp"
#include "Game.hpp"

bool isHelpFlag(int argc, const char** argv) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            return true;
        }
    }
    return false;
}

void printManual() {
    std::cout << "Program is supposed to take 2 parameters from the commandline.\n";
    std::cout << "First one is a directory, where txt files containing initial game states, should be kept.\n";
    std::cout << "Second one is optional, it is an output file, designed to save game results. \n";
    std::cout << "If the second parameter is omitted, game results will be printed to the console.\n";
    std::cout << "Example: ./bowling inputDirectory results.txt\n";
}

int main(int argc, const char** argv) {
    if (argc <= 1) {
        return -1;
    }
    if (isHelpFlag(argc, argv)) {
        printManual();
        return 0;
    }
    BowlingAlley alley(argv[1]);
    if (argc >= 3) {
        std::ofstream file(argv[2]);
        file << alley.getOutputString();
    } else {
        std::cout << alley.getOutputString();
    }
}
