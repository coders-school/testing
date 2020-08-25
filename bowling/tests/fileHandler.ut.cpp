#include "catch.hpp"

#include "fileHandler.hpp"

#include <string>
#include <utility>

using Access = FileHandler::FileAccess;

SCENARIO("FileHandler object can be created for input", "FileHandler")
{
    auto [testFileName, expectedIsFileOpened] =
        GENERATE(std::make_pair("testDirectory/testFile1.txt", true),
                 std::make_pair("testDirectory/emptyFile.txt", true),
                 std::make_pair("noExistingFile.txt", false),
                 std::make_pair("", false));

    GIVEN("File name: " << testFileName)
    {
        WHEN("FileHandler object is created")
        {
            FileHandler testFileHandler(testFileName, Access::INPUT);
            THEN("File is opened for read")
            {
                REQUIRE(testFileHandler.isFileOpened() == expectedIsFileOpened);
            }
        }
    }
}
