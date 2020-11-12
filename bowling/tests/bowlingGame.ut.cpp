#include <sstream>

#include "bowlingGame.hpp"
#include "catch.hpp"

using Catch::Matchers::StartsWith;

SCENARIO("BowlingGame class can check if help is to be printed and trigger printing", "bowlingGame")
{
    int testArgc = 2;
    std::string expectedHelpBeginning{"BowlingGame <input directory> <output file>"};

    {
        const char* testArgv[] = {"programName", "--help", NULL};

        GIVEN("argc = " << testArgc
                        << " and argv = {\""
                        << (testArgv[0] ? testArgv[0] : "") << "\", \""
                        << (testArgv[1] ? testArgv[1] : "") << "\", \""
                        << (testArgv[2] ? testArgv[2] : "") << "\"}")
        {
            WHEN("BowlingGame object is created")
            {
                BowlingGame testBowlingGame(testArgc, testArgv);
                THEN("isHelpToBePrinted() reeturns true and help is printed")
                {
                    REQUIRE(testBowlingGame.isHelpToBePrinted());

                    std::stringstream ss;
                    ss << printHelp();
                    REQUIRE_FALSE(ss.str().empty());
                    REQUIRE_THAT(ss.str(),
                                 StartsWith(expectedHelpBeginning));
                }
            }
        }
    }
    {
        const char* testArgv[] = {"programName", "-h", NULL};

        GIVEN("argc = " << testArgc
                        << " and argv = {\""
                        << (testArgv[0] ? testArgv[0] : "") << "\", \""
                        << (testArgv[1] ? testArgv[1] : "") << "\", \""
                        << (testArgv[2] ? testArgv[2] : "") << "\"}")
        {
            WHEN("BowlingGame object is created")
            {
                BowlingGame testBowlingGame(testArgc, testArgv);
                THEN("isHelpToBePrinted() reeturns true and help is printed")
                {
                    REQUIRE(testBowlingGame.isHelpToBePrinted());

                    std::stringstream ss;
                    ss << printHelp();
                    REQUIRE_FALSE(ss.str().empty());
                    REQUIRE_THAT(ss.str(),
                                 StartsWith(expectedHelpBeginning));
                }
            }
        }
    }
}

SCENARIO("Should save scores in file")
{
    GIVEN("Three arguments for start")
    {
        const char* resultFilePath = "../tests/testDirectory/gameScores/result1.txt";
        const char* userInput[] = {"./bowling", "../tests/testDirectory/goodInput/", resultFilePath};
        BowlingGame bowlingGame(3, userInput);
        WHEN("Called function save scores")
        {
            bowlingGame.calculateScores();
            bowlingGame.outputScores();
            THEN("Should save scores in file")
            {
                std::stringstream expectedFile;
                expectedFile << "### lane1: game finished ###\n"
                             << "Matylda 167\n\n"
                             << "### lane2: game finished ###\n"
                             << "Pimpek 300\n\n"
                             << "### lane3: game in progress ###\n"
                             << "Zuzka 31\n\n";
                std::ifstream fileStream(resultFilePath);
                std::stringstream resultFile;
                if (fileStream) {
                    resultFile << fileStream.rdbuf();
                    fileStream.close();
                }
                REQUIRE(expectedFile.str() == resultFile.str());
            }
        }
    }
}
