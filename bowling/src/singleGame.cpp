#include "singleGame.hpp"

SingleGame::SingleGame(std::string& gameInput)
{
    this->gameInput_ = gameInput;
    parseGameInput();
}

SingleGame::~SingleGame() {}

void SingleGame::parseGameInput() {
    this->readPlayerName();
    this->putScoresToVector();
    this->checkGameStatus();
}

void SingleGame::readPlayerName() {}

void SingleGame::putScoresToVector() {}

void SingleGame::checkGameStatus() {}

void SingleGame::countScore() {}

std::string SingleGame::getPlayerName() const
{
    return this->playerName_;
}

size_t SingleGame::getScore() const
{
    return this->score_;
}

enum SingleGame::GameStatus SingleGame::getGameStatus() const
{
    return gameStatus_;
}