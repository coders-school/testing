#include "gtest/gtest.h"

#include "BowlingAlley.hpp"

#include <filesystem>

class BowlingAlleyTests : public ::testing::Test {
protected:
    std::filesystem::path path = "/home/marcinati/Github/testing/bowling/tests";
    BowlingAlley bowlingAlley{path};

};

TEST_F(BowlingAlleyTests, ConstructedBowlingAlleyShouldHaveACurrentPathTheSameAsTheConstructorHad) {
    EXPECT_EQ(bowlingAlley.getCurrentPath(), path);
}

TEST_F(BowlingAlleyTests, CountFilesInCurrentPath) {
    EXPECT_EQ(bowlingAlley.countFiles(), 2); //path to files with class tests, when you add new files increase number
}