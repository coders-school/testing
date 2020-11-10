#include "gtest/gtest.h"

#include "BowlingAlley.hpp"

#include <filesystem>
#include <fstream>
class BowlingAlleyTests : public ::testing::Test {
   protected:
    std::filesystem::path path = "../games";
    BowlingAlley bowlingAlley{path};
};

TEST_F(BowlingAlleyTests, bowlingAlleyCanBeLoadedFromFolder) {
    bowlingAlley.loadFromFolder(path);
    auto expectedOutput{
        "### Lane 1: game finished ###\n"
        "Michael 158\n"
        "Radek 166\n"
        "### Lane 2: game in progress ###\n"
        "Name1 21\n"
        "Name2 17\n"
        "24\n"
        "### Lane 3: no game ###\n"};
    EXPECT_EQ(bowlingAlley.getOutputString(), expectedOutput);
}
