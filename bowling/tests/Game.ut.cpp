#include <gtest/gtest.h>
#include "Game.hpp"

constexpr char inputOneFileDirectoryPath[] = "../input/one-file";
constexpr char inputManyFilesDirectoryPath[] = "../input/many-files";
constexpr char inputEmptyFileDirectoryPath[] = "../input/empty-file";
[[maybe_unused]] constexpr char inputEmptyDirectoryDirectoryPath[] = "../input/empty-dir";

constexpr char oneFileResultOutput[] = "../tests/results/resultOneFile.txt";
constexpr char manyFilesResultOutput[] = "../tests/results/resultManyFiles.txt";
constexpr char emptyFileResultOutput[] = "../tests/results/resultEmptyFile.txt";
[[maybe_unused]] constexpr char emptyDirectoryResultOutput[] = "../tests/results/resultEmptyDirectory.txt";

[[maybe_unused]] constexpr char expectedEmptyDirectory[] = "";
constexpr char expectedOneFile[] =
    "### Lane 1: game in progress ###\n"
    "Name1 18\n"
    "Name2 17\n"
    " 24\n";
constexpr char expectedManyFiles[] =
    "### Lane 1: game in progress ###\n"
    "Name1 18\n"
    "Name2 17\n"
    " 24\n"
    "### Lane 2: no game ###\n"
    "### Lane 3: game finished ###\n"
    "Michael 167\n"
    "Radek 90\n";
constexpr char expectedEmptyFile[] = "### Lane 1: no game ###\n";

void loadResultFromFileAndCheckIfIsEqualToExpected(const char fileOutput[], const char expectedOutput[]) {
    std::ifstream testFile(fileOutput, std::ios_base::in);
    std::stringstream os;
    std::string line;
    if (testFile.is_open()) {
        while (getline(testFile, line)) {
            os << line << '\n';
        }
        testFile.close();
    } else {
        FAIL() << "Cannot open file\n";
    }

    ASSERT_EQ(os.str(), expectedOutput);
}

TEST(GameTest, GameResultStringFromDirectoryWithOneFileShouldBeEqualToExpectedOneFile) {
    Game game{inputOneFileDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedOneFile);
}

TEST(GameTest, GameResultFromDirectoryWithOneFileSavedToFileAndOpenedFromItShouldBeEqualToExpectedOneFile) {
    Game game{inputOneFileDirectoryPath, oneFileResultOutput};
    game.saveDataToFile();
    loadResultFromFileAndCheckIfIsEqualToExpected(oneFileResultOutput, expectedOneFile);
}

TEST(GameTest, GameResultStringFromDirectoryWithManyFilesShouldBeEqualToExpectedManyFiles) {
    Game game{inputManyFilesDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedManyFiles);
}

TEST(GameTest, GameResultFromDirectoryWithManyFilesSavedToFileAndOpenedFromItShouldBeEqualToExpectedManyFiles) {
    Game game{inputManyFilesDirectoryPath, manyFilesResultOutput};
    game.saveDataToFile();
    loadResultFromFileAndCheckIfIsEqualToExpected(manyFilesResultOutput, expectedManyFiles);
}

TEST(GameTest, GameResultStringFromDirectoryWithEmptyFileShouldBeEqualToExpectedEmptyFile) {
    Game game{inputEmptyFileDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedEmptyFile);
}

TEST(GameTest, GameResultFromDirectoryWithEmptyFileSavedToFileAndOpenedFromItShouldBeEqualToExpectedEmptyFile) {
    Game game{inputEmptyFileDirectoryPath, emptyFileResultOutput};
    game.saveDataToFile();
    loadResultFromFileAndCheckIfIsEqualToExpected(emptyFileResultOutput, expectedEmptyFile);
}

TEST(DISABLED_GameTest, GameResultStringFromEmptyDirectoryShouldBeEqualToExpectedEmptyDirectory) {
    Game game{inputEmptyDirectoryDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedEmptyDirectory);
}

TEST(DISABLED_GameTest, GameResultFromEmptyDirectoryFilesSavedToFileAndOpenedFromItShouldBeEqualToExpectedEmptyDirectory) {
    Game game{inputEmptyDirectoryDirectoryPath, emptyDirectoryResultOutput};
    game.saveDataToFile();
    loadResultFromFileAndCheckIfIsEqualToExpected(emptyDirectoryResultOutput, expectedEmptyDirectory);
}
