#pragma once

#include <iostream>
#include <string>
#include <vector>

class SingleGame {
public:
    enum class GameStatus {
        FINISHED,
        IN_PROGRESS,
        NOT_STARTED
    };

    SingleGame(std::string gameInput);
    ~SingleGame();

    std::string getPlayerName() const { return playerName_; };
    std::vector<std::size_t> getRolls() const { return rolls_; };
    std::size_t getScore() const { return score_; };
    std::string getGameInput() const { return gameInput_; };
    GameStatus getGameStatus() const { return gameStatus_; };
    friend std::ostream& operator<<(std::ostream& os, const SingleGame& singleGame);

private:
    std::string gameInput_{};
    std::string playerName_{};
    std::string bowlingCharacters_{};
    std::vector<size_t> rolls_{};
    size_t score_{};

    std::string getbowlingCharacters() const { return bowlingCharacters_; };

    GameStatus gameStatus_{};

    void setRolls(std::size_t point);
    void setPlayerName(std::string playerName) { playerName_ = playerName; };
    void setGameInput(std::string gameInput) { gameInput_ = gameInput; };
    void setbowlingCharacters(std::string bowlingCharacters) { bowlingCharacters_ = bowlingCharacters; };
    void makePointsFromSigns();

    void parseGameInput();
    void putScoresToVector();
    void checkGameStatus();
    void countScore();
    bool isNotPlayerName();
    bool isNotbowlingCharacters();
    bool isNotBowlingGameInput();
    void eraseSpaces();
    bool isNotAllowedChar();
    bool isNotBowlingOrder();

    bool isGameFinished();
    bool isGameNotStarted();

    bool isStrike(size_t firstInFrame);
    bool isSpare(size_t firstInFrame);
    size_t getBonusPointsForStrike(size_t firstInFrame);
    size_t getBonusPointsForSpare(size_t firstInFrame);
    size_t getPointsForRegularGame(size_t firstInFrame);
};
