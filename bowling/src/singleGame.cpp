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

void SingleGame::putScoresToVector() {

    auto foundIndexAfterName = getGameInput().find(':');
    if (foundIndexAfterName != std::string::npos) {
        setBowlingSigns(getGameInput().substr(++foundIndexAfterName));
    }
    std::cout << "BowlingSigns " << getBowlingSings() << "\n";

    for(auto sign : getBowlingSings()) {
        if(sign == '|'){
            continue;
        }
        if(sign == 'X'){
            rolls_.push_back(10);
        }
        if(sign == '/'){
            rolls_.push_back(10 - (rolls_.back()));
        }
        if(sign == '-') {
            rolls_.push_back(0);
        }
        if(sign == '1') {
            rolls_.push_back(1);
        }
        if(sign == '2') {
            rolls_.push_back(2);
        }
        if(sign == '3') {
            rolls_.push_back(3);
        }
        if(sign == '4') {
            rolls_.push_back(4);
        }
        if(sign == '5') {
            rolls_.push_back(5);
        }
        if(sign == '6') {
            rolls_.push_back(6);
        }
        if(sign == '7') {
            rolls_.push_back(7);
        }
        if(sign == '8') {
            rolls_.push_back(8);
        }
        if(sign == '9') {
            rolls_.push_back(9);
        }
    }
    
}

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
