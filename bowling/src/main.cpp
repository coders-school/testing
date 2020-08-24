#include <iostream>

#include "argumentParser.hpp"
#include "bowlingGame.hpp"
#include "directoryHandler.hpp"
#include "fileHandler.hpp"
#include "lane.hpp"
#include "singleGame.hpp"

int main(int argc, char** argv)
{
    std::cout << "Works!\n";
    std::cout << "Nums of args: " << argc << "\n";

    if (argv[1]) {
        std::cout << "First argument: " << argv[0] << "\n";
        std::cout << "Second argument: " << argv[1] << "\n";
    }

    return 0;
}
