#include "gtest/gtest.h"

#include "Game.hpp"

#include <filesystem>
#include <fstream>

class GameTests : public ::testing::Test {
    protected:
    Game game;
};

using GameDeathTests = GameTests;

TEST_F(GameDeathTests, GameIsLoadedFromNonExistingFile) {
    std::string fileName{"hiashdksjd.txt"};
    std::string expectedMessage = "file " + fileName + " could not be opened!";
    ASSERT_DEATH(game.loadFromFile(fileName), expectedMessage);
}

