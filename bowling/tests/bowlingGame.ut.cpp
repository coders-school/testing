#include "catch.hpp"

#include "bowlingGame.hpp"
#include "bowlingGameStub.hpp"

#include <sstream>

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
        const char* userInput[] = {"./bowling", "../tests/testDirectory/goodInput/", "../tests/testDirectory/gameScores/result1.txt"};
        BowlingGameStub bowlingGameStub(3, userInput);
        WHEN("Called function save scores")
        {
            bowlingGameStub.calculateScores();
            std::stringstream ss = bowlingGameStub.saveScores();
            THEN("Should save scores in file")
            {
                std::vector<std::string> expectedOutput{
                    "### lane3 : game in progress###",
                    "Zuzka 31",

                    "### lane1 : game finished###",
                    "Matylda 167",

                    "### lane2 : game finished###",
                    "Pimpek 300"};

                int i = 0;
                std::string temp{};
                std::string wholeLine{};

                while (ss >> temp) {
                    wholeLine.append(temp);
                    if (temp == "\n") {
                        REQUIRE(wholeLine == expectedOutput[i++]);
                        wholeLine.clear();
                    }
                }
            }
        }
    }
}
