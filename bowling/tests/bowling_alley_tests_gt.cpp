#include "gtest/gtest.h"

#include "BowlingAlley.hpp"
#include "Game.hpp"

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

TEST_F(BowlingAlleyTests, bowlingAlleyThrowsWhenLoadedNotFromAFolder) {
    std::string notExistingPath{"iDontExist"};
    EXPECT_THROW(bowlingAlley.loadFromFolder(notExistingPath), std::invalid_argument);
}

TEST_F(BowlingAlleyTests, bowlingAlleyReturnsOutputStringForManyGames) {
    std::string expectedOutput{};
    const auto& games = bowlingAlley.getGames();
    for (size_t i{0}; i < games.size(); ++i) {
        expectedOutput += games[i]->getOutputString(i + 1);
    }
    EXPECT_EQ(bowlingAlley.getOutputString(), expectedOutput);
}
