#include <cstring>
#include <iostream>
#include "Game.hpp"


void printHelp() {
    std::cout << "******   BOWLING GAME    ******\n";
    std::cout << "\tDIRECTORY  \t-directory which contains input files for game\n";
    std::cout << "\t[FILE]  \t-optional file to save results of game\n";
    std::cout << "example of use:  ./bowling inputDirectory results.txt\n";
}

int main() {
    //int main(int argc, char* argv[]) {
    // if ((argc == 2 && strcmp(argv[1], "--help") == 0) || strcmp(argv[1], "-h") == 0) {
    //     printHelp();
    // }

    // std::string inputDirectoryName = argv[1];
    // std::string resultOutputFileName;

    // if (argc == 3) {
    //     resultOutputFileName = argv[2];
    // }

    // std::cout << inputDirectoryName << '\n';
    // if (!resultOutputFileName.empty()) {
    //     std::cout << resultOutputFileName << '\n';
    // }

    Game game{"../input"};
    game.printInputData();
    game.printResults();
    return 0;
}
