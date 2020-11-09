#include <gtest/gtest.h>
#include "Game.hpp"

constexpr char inputEmptyDirectoryDirectoryPath[] = "../input/empty-dir";
constexpr char inputOneFileDirectoryPath[] = "../input/one-file";
constexpr char inputManyFilesDirectoryPath[] = "../input/many-files";
constexpr char inputEmptyFileDirectoryPath[] = "../input/empty-file";


constexpr char emptyDirectoryResultOutput[] = "../tests/results/resultEmptyFiles.txt";
constexpr char oneFileResultOutput[] = "../tests/results/resultOneFile.txt";
constexpr char manyFilesResultOutput[] = "../tests/results/resultManyFiles.txt";
constexpr char emptyFileResultOutput[] = "../tests/results/resultEmptyFile.txt";


constexpr char expectedEmptyDirectory[] = "";
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

TEST(GameTest, GameResultStringFromEmptyDirectoryShouldBeEqualToExpectedEmptyDirectory) {
    Game game{inputEmptyDirectoryDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedEmptyDirectory);
}

TEST(GameTest, GameResultFromEmptyDirectoryFilesSavedToFileAndOpenedFromItShouldBeEqualToExpectedEmptyDirectory) {
    Game game{inputEmptyDirectoryDirectoryPath, emptyDirectoryResultOutput};
    game.saveDataToFile();

    std::ifstream testFile(emptyDirectoryResultOutput, std::ios_base::in);
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
    ASSERT_EQ(os.str(), expectedEmptyDirectory);
}

TEST(GameTest, GameResultStringFromDirectoryWithOneFileShouldBeEqualToExpectedOneFile) {
    Game game{inputOneFileDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedOneFile);
}

TEST(GameTest, GameResultFromDirectoryWithOneFileSavedToFileAndOpenedFromItShouldBeEqualToExpectedOneFile) {
    Game game{inputOneFileDirectoryPath, oneFileResultOutput};
    game.saveDataToFile();

    std::ifstream testFile(oneFileResultOutput, std::ios_base::in);
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
    ASSERT_EQ(os.str(), expectedOneFile);
}

TEST(GameTest, GameResultStringFromDirectoryWithManyFilesShouldBeEqualToExpectedManyFiles) {
    Game game{inputManyFilesDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedManyFiles);
}

TEST(GameTest, GameResultFromDirectoryWithManyFilesSavedToFileAndOpenedFromItShouldBeEqualToExpectedManyFiles) {
    Game game{inputManyFilesDirectoryPath, manyFilesResultOutput};
    game.saveDataToFile();

    std::ifstream testFile(manyFilesResultOutput, std::ios_base::in);
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
    ASSERT_EQ(os.str(), expectedManyFiles);
}

TEST(GameTest, GameResultStringFromDirectoryWithEmptyFileShouldBeEqualToExpectedEmptyFile) {
    Game game{inputEmptyFileDirectoryPath};
    ASSERT_EQ(game.getGameResult(), expectedEmptyFile);
}

TEST(GameTest, GameResultFromDirectoryWithEmptyFileSavedToFileAndOpenedFromItShouldBeEqualToExpectedEmptyFile) {
    Game game{inputEmptyFileDirectoryPath, emptyFileResultOutput};
    game.saveDataToFile();

    std::ifstream testFile(emptyFileResultOutput, std::ios_base::in);
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
    ASSERT_EQ(os.str(), expectedEmptyFile);
}
