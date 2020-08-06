#include "gtest/gtest.h"

#include "Game.hpp"

class GameTests : public ::testing::Test {
    protected:
    Game game;
};

using GameDeathTests = GameTests;

TEST_F(GameDeathTests, GameIsLoadedFromNonExistingFile) {
    std::string fileName{"example.txt"};
    std::string expectedMessage = "file " + fileName + " could not be opened!";
    ASSERT_DEATH(game.loadFromFile("example.txt"), expectedMessage);
}
