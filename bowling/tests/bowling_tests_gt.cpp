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
    ASSERT_DEATH(game.loadFromFile(filePath), expectedMessage);
}

TEST_F(GameTests, loadFromFileShouldLoadPlayerName) {
    std::string expectedPlayerName{"Franek"};
    file << "Franek:\n";
    file.flush();
    game.loadFromFile(filePath);
    ASSERT_EQ(game.getPlayers()[0].name, expectedPlayerName);
}

TEST_F(GameTests, loadFromFileShouldLoadEmptyPlayerName) {
    std::string expectedPlayerName{};
    std::string fileName{};
}
