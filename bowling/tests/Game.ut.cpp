#include <gtest/gtest.h>
#include "Game.hpp"

constexpr char inputDirectoryPath[] = "../input/";
constexpr char resultOutput[] = "../tests/resultTest.txt";
constexpr char expected[] =
    "### Lane 1: game in progress ###\n"
    "Name1 18\n"
    "Name2 17\n"
    " 24\n"
    "### Lane 2: no game ###\n"
    "### Lane 3: game finished ###\n"
    "Michael 167\n"
    "Radek 90\n";

TEST(GameTest, GameResultStringFromFunctionShouldBeEqualToExpected) {
    Game game{inputDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expected);
}

TEST(GameTest, GameResultSavedToFileAndOpenedFromItShouldBeEqualToExpected) {
    Game game{inputDirectoryPath, resultOutput};
    game.saveDataToFile();

    std::ifstream testFile(resultOutput, std::ios_base::in);
    std::stringstream os;
    std::string line;
    if (testFile.is_open()) {
        while (getline(testFile, line)) {
            os << line << '\n';
        }
        testFile.close();
    } else {
        std::cout << "Cannot open file\n";
    }
    ASSERT_EQ(os.str(), expected);
}
