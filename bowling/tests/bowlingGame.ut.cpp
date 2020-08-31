#include "catch.hpp"

#include "bowlingGame.hpp"

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
                    ss << testBowlingGame.printHelp();
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
                    ss << testBowlingGame.printHelp();
                    REQUIRE_FALSE(ss.str().empty());
                    REQUIRE_THAT(ss.str(),
                                 StartsWith(expectedHelpBeginning));
                }
            }
        }
    }
}
