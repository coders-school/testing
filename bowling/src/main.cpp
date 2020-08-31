#include "bowlingGame.hpp"

int main(int argc, char** argv)
{
    BowlingGame bg(argc, (const char**)argv);

    if (bg.isHelpToBePrinted()) {
        std::cout << bg.printHelp() << "\n";
    }
    else if (!bg.isHelpToBePrinted() && ((argc == 2) || (argc == 3))) {
        bg.calculateScores();
        bg.outputScores();
    }
    else {
        std::cout << bg.printHelp() << "\n";
    }

    return 0;
}
