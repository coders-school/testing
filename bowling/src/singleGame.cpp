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

void SingleGame::putScoresToVector()
{
    auto foundIndexAfterName = getGameInput().find(':');
    if (foundIndexAfterName != std::string::npos) {
        setBowlingSigns(getGameInput().substr(++foundIndexAfterName));
    }

    const size_t MAXPOINT = 10;
    const size_t NOPOINT = 0;

    for (auto sign : getBowlingSings()) {
        if (sign == '|') {
            continue;
        }
        if (sign == 'X') {
            setRolls(MAXPOINT);
        }
        if (sign == '/') {
            setRolls(MAXPOINT - (getRolls().back()));
        }
        if (sign == '-') {
            setRolls(NOPOINT);
        }
        if (std::isdigit(sign)) {
            setRolls(sign - '0');
        }
    }
}

void SingleGame::checkGameStatus() {}

void SingleGame::countScore() {}

void SingleGame::setRolls(std::size_t point)
{
    this->rolls_.push_back(point);
}

void SingleGame::setPlayerName(std::string playerName)
{
    this->playerName_ = playerName;
}

std::string SingleGame::getPlayerName() const
{
    return this->playerName_;
}

void SingleGame::setBowlingSigns(std::string bowlingSigns)
{
    this->bowlingSigns_ = bowlingSigns;
}

std::string SingleGame::getBowlingSings() const
{
    return this->bowlingSigns_;
}

std::vector<std::size_t> SingleGame::getRolls() const
{
    return this->rolls_;
}

std::size_t SingleGame::getScore() const
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
