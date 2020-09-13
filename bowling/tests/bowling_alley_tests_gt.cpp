#include "gtest/gtest.h"

#include "BowlingAlley.hpp"

#include <filesystem>

class BowlingAlleyTests : public ::testing::Test {
protected:
    std::filesystem::path path = "C:/test";
    BowlingAlley bowlingAlley{path};

};

TEST_F(BowlingAlleyTests, ConstructedBowlingAlleyShouldHaveACurrentPathTheSameAsTheConstructorHad) {
    EXPECT_EQ(bowlingAlley.getCurrentPath(), path);
}