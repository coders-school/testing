#include "catch.hpp"

#include "lane.hpp"

#include <iostream>
#include <string>

SCENARIO("Lane class constructor takes one string type argument", "[creating lane object]")
{
    auto [dirName, expectedLaneName] =
        GENERATE(
            std::make_pair("lane", "lane"),
            std::make_pair("lane1.txt", "lane1"),
            std::make_pair("lane2.doc", "lane2"),
            std::make_pair("lane3.odt", "lane3"),
            std::make_pair("lane4.cpp", "lane4"),
            std::make_pair("", ""),
            std::make_pair(".hidden", ".hidden"),
            std::make_pair("./lane.txt", "lane"),
            std::make_pair("../lane.txt", "lane"),
            std::make_pair("../test/lane.txt", "lane"),
            std::make_pair("/home/bowling/lane.txt", "lane"));

    GIVEN("Argument as a directory name: " << dirName)
    {
        WHEN("Lane object is creating")
        {
            Lane lane(dirName);

            THEN("Value laneName_ is equal to filename without extension: " << expectedLaneName)
            {
                REQUIRE(lane.getLaneName() == expectedLaneName);
            }
        }
    }
}
