#include <iostream>
#include <string>

#include "game.hpp"

// void oneParameter(const std::string& param) {
//     if (param.front() == '-') {
//         if (param == "-h" || param == "--help") {
//             Game::printHelp();
//             return;
//         } else {
//             std::cout << "Unknown parameter: " << param << '\n';
//             return;
//         }
//     }
// }

static void printHelp() {
    std::cout << "This is simple application which count points in Bowling Game \n"
              << "Program takes two parameters:\n"
              << "1. Is directory which includes txt files with game state"
              << " on bowling lanes\n"
              << "2.(optional) Is optional output file where processed results is saved\n"
              << "If you don't give second parameter, results has been printed to screen\n"
              << "Example of use: \n"
              << "***** ./bowling inputDirectory results.txt\n"
              << "***** ./bowling inputDirectory";
}

int main(int argc, char* argv[]) {
    std::string inputDirectory;
    std::string outputFile;
    if (argc == 1) {
        std::cout << "You haven't specified the path to the input files\n";
        return EXIT_FAILURE;
    } else if ((argc == 2 && std::string(argv[1]) == "--help")
        || (argc == 2 && std::string(argv[1]) == "--h")) {
        printHelp();
        return EXIT_SUCCESS;
    } else if (argc == 3) {
        inputDirectory = argv[1];
        outputFile = argv[2];
        return EXIT_SUCCESS;
    } else if (argc >= 4) {
        std::cout << "Too many arguments\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
