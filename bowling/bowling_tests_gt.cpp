#include "gtest/gtest.h"

#include "Game.hpp"

class GameTests : public ::testing::Test {
    protected:
    Game game;
};

TEST_F(GameTests, GameCanBeLoadedFromFile) {
    game.loadFromFile("example.txt");
}
