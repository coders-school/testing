#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

#include "bowlingLane.hpp"

struct TestBowlingLine : public ::testing::Test {
    std::vector<std::unique_ptr<Player>> players;
    std::vector<std::pair<int, int>> points{{1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}}; 
};

TEST_F(TestBowlingLine, checkPrintResultToScreen) {
    players.emplace_back(std::make_unique<Player>("player", points));
    BowlingLane bl(std::move(players));
    EXPECT_TRUE(bl.checkGameStatus());
    
    bl.checkGameStatus();
    EXPECT_EQ(bl.convertEnumToString(), "Finished ");
}

TEST_F(TestBowlingLine, checkSetPLayer) {
    BowlingLane bl(std::move(players));
    bl.setPlayer("player", points);
    bl.checkGameStatus();
    EXPECT_EQ(bl.getResult(), "Finished player 30");
}
