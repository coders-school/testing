#include "singleGame.hpp"

#include <algorithm>

SingleGame::SingleGame(std::string gameInput)
{
    this->gameInput_ = gameInput;
    parseGameInput();
}

SingleGame::~SingleGame() {}

void SingleGame::parseGameInput()
{
    this->readPlayerName();
    this->putScoresToVector();
    this->checkGameStatus();
}

void SingleGame::readPlayerName()
{
    auto foundIndexAfterName = getGameInput().find(':');
    if (foundIndexAfterName != std::string::npos) {
        if (foundIndexAfterName) {
            setPlayerName(getGameInput().substr(0, foundIndexAfterName));
        }
        else {
            std::string anonymousPlayer("Anonymous");
            setPlayerName(anonymousPlayer);
        }
    }
}

void SingleGame::putScoresToVector() {}

void SingleGame::checkGameStatus() {}

void SingleGame::countScore() {}

void SingleGame::setPlayerName(std::string playerName)
{
    this->playerName_ = playerName;
}

std::string SingleGame::getPlayerName() const
{
    return this->playerName_;
}

size_t SingleGame::getScore() const
{
    return this->score_;
}

std::string SingleGame::getGameInput() const
{
    return gameInput_;
}

enum SingleGame::GameStatus SingleGame::getGameStatus() const
{
    return gameStatus_;
}
