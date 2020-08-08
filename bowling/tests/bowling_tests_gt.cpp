#include "gtest/gtest.h"

#include "Game.hpp"

#include <filesystem>
#include <fstream>

class GameTests : public ::testing::Test {
   protected:
    Game game;
    std::ofstream file;
    std::string filePath;

    void SetUp() override {
        std::string fileName = "/test_file.txt";
        filePath = std::filesystem::current_path().string() + fileName;
        file.open(filePath, std::ios_base::out);
    }

    void TearDown() override {
        file.close();
        std::filesystem::remove(filePath);
    }
};

using GameDeathTests = GameTests;

TEST_F(GameDeathTests, GameIsLoadedFromNonExistingFile) {
    std::string fileName{"hiashdksjd.txt"};
    std::string filePath = std::filesystem::current_path().string() + fileName;
    std::string expectedMessage = "file " + filePath + " could not be opened!";
    EXPECT_DEATH(game.loadFromFile(filePath), expectedMessage);
}

TEST_F(GameTests, loadFromFileShouldLoadPlayerName) {
    std::string expectedPlayerName{"Franek"};
    file << "Franek:\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].name, expectedPlayerName);
}

TEST_F(GameTests, loadFromFileShouldLoadEmptyPlayerName) {
    std::string expectedPlayerName{};
    file << ":\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].name, expectedPlayerName);
}

TEST_F(GameTests, loadFromFileShouldLoadAllPlayersNames) {
    std::vector<std::string> expectedPlayerNames{"Wojtek", "Jadwiga", "Robert"};
    file << "Wojtek:27|12\n";
    file << "Jadwiga:33|18\n";
    file << "Robert:X\n";
    file.flush();
    game.loadFromFile(filePath);
    ASSERT_EQ(game.getPlayers().size(), 3);
    EXPECT_EQ(game.getPlayers()[0].name, expectedPlayerNames[0]);
    EXPECT_EQ(game.getPlayers()[1].name, expectedPlayerNames[1]);
    EXPECT_EQ(game.getPlayers()[2].name, expectedPlayerNames[2]);
}

TEST_F(GameTests, loadFromFileShouldNotLoadAnyPlayerFromEmptyFile) {
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers().size(), 0);
}

TEST_F(GameTests, loadFromFileShouldLoadPlayerRolls) {
    std::vector<Frame> expectedPlayerRolls{{'6', '3'}, {'1', '8'}, {'X', ' '}, {'4', '/'}};
    file << "Name:63|18|X|4/\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].rolls, expectedPlayerRolls);
}
