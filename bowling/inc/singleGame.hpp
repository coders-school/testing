#pragma once

#include <iostream>
#include <string>
#include <vector>

class SingleGame {
private:
    std::string gameInput_{};
    std::string playerName_{};
    std::string bowlingSigns_{};
    std::vector<size_t> rolls_{};
    size_t score_{};

    enum class GameStatus {
        FINISHED,
        IN_PROGRESS,
        NOT_STARTED
    };

    GameStatus gameStatus_{};

    void parseGameInput();
    void readPlayerName();
    void putScoresToVector();
    void checkGameStatus();
    void countScore();

public:
    SingleGame(std::string gameInput);
    ~SingleGame();

    void setPlayerName(std::string playerName);
    void setBowlingSigns(std::string bowlingSigns);

    std::string getPlayerName() const;
    std::string getBowlingSings() const;
    std::vector<std::size_t> getRolls() const;
    std::size_t getScore() const;
    std::string getGameInput() const;
    enum GameStatus getGameStatus() const;
    friend std::ostream& operator<<(std::ostream& os, const SingleGame& singleGame);
};
