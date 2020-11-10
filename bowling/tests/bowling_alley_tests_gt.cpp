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
    auto expectedGameCount{3};
    EXPECT_EQ(bowlingAlley.getGames().size(), expectedGameCount);
}
