#include <gtest/gtest.h>
#include "Game.hpp"

constexpr char inputDirectoryPath[] = "../input/";
constexpr char resultOutput[] = "../tests/resultTest.txt";

TEST(GameTest, ResultShouldBeEqualToInitialFile) {
    Game game{inputDirectoryPath, resultOutput};
    game.saveDataToFile();
    std::string expected = "### Lane 1: game in progress ###"
                           "Name1 18"
                           "Name2 17"
                           " 24"
                           "### Lane 2: no game ###"
                           "### Lane 3: game finished ###"
                           "Michael 167"
                           "Radek 90";

    std::ifstream testFile(resultOutput, std::ios_base::in);
    std::stringstream os;
    std::string line;
    if(testFile.is_open()){
        while(getline(testFile,line)){
            os << line;
        }
        testFile.close();
    } else {
        std::cout << "Cannot open file\n";
    }
    ASSERT_EQ(os.str(), expected);
}
