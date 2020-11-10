#include "singleGame.hpp"

#include <algorithm>

SingleGame::SingleGame(std::string gameInput)
{
    setGameInput(gameInput);
    eraseSpaces();

    if (isNotBowlingGameInput()) {
        std::string badInput = "";
        setGameInput(badInput);
    }

    parseGameInput();
    countScore();
}

SingleGame::~SingleGame() {}

void SingleGame::parseGameInput()
{
    putScoresToVector();
    checkGameStatus();
}

bool SingleGame::isNotBowlingGameInput()
{
        return (getGameInput().empty() ||
        isNotPlayerName() ||
        isNotBowlingCharacters() ||
        isNotAllowedChar() ||
        isNotBowlingOrder());
}

void SingleGame::eraseSpaces()
{
    std::string gameInput = getGameInput();
    gameInput.erase(std::remove(gameInput.begin(), gameInput.end(), ' '),
                    gameInput.end());
    setGameInput(gameInput);
}

bool SingleGame::isNotAllowedChar()
{
    std::string gameInput = getGameInput();

    const std::string ALLOWEDCHARACTERS = "X/-|123456789";

    auto foundIndexAfterName = gameInput.find(':');

    if (getGameInput() == ":") {
        return true;
    }

    if (foundIndexAfterName != std::string::npos) {
        auto foundNotAllowedCharacter = gameInput.find_first_not_of(ALLOWEDCHARACTERS, ++foundIndexAfterName);
        if (foundNotAllowedCharacter != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool SingleGame::isNotBowlingOrder()
{
    std::string bowlingCharacters = getbowlingCharacters();

    size_t ballThrows = 1;
    bool expectedPipe = false;
    bool expectedSecondPipe = false;

    for (auto sign : bowlingCharacters) {
        if (expectedSecondPipe) {
            expectedSecondPipe = false;
            expectedPipe = false;
            continue;
        }

        if (expectedPipe && (sign == '|')) {
            if (ballThrows == 21) {
                expectedSecondPipe = true;
                expectedPipe = false;
                continue;
            }
            else {
                expectedPipe = false;
                continue;
            }
            return true;
        }

        if (ballThrows % 2) {
            if ((std::isdigit(sign) || sign == 'X' || sign == '-') && (!expectedPipe)) {
                if (sign == 'X') {
                    if (ballThrows != 21) {
                        expectedPipe = true;
                    }
                    ballThrows++;
                }
                ballThrows++;
            }
            else {
                return true;
            }
        }
        else {
            if ((std::isdigit(sign) || sign == '/' || sign == '-') && (!expectedPipe)) {
                ballThrows++;
                expectedPipe = true;
            }
            else {
                return true;
            }
        }
    }
    return false;
}

bool SingleGame::isNotPlayerName()
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
    else {
        return true;
    }
    return false;
}

bool SingleGame::isNotBowlingCharacters()
{
    auto foundIndexAfterName = getGameInput().find(':');

    if (foundIndexAfterName != std::string::npos) {
        setbowlingCharacters(getGameInput().substr(++foundIndexAfterName));
    }
    else {
        return true;
    }
    return false;
}

void SingleGame::putScoresToVector()
{
    makePointsFromSigns();
}

bool SingleGame::isGameFinished()
{
    const auto foundIndexOfBonus = getbowlingCharacters().find("||");
    if (foundIndexOfBonus == std::string::npos) {
        return false;
    }
    else {
        const auto rollsBeforeBonus = getbowlingCharacters().substr(0, foundIndexOfBonus);
        const auto foundIndexOfLastFrameStart = rollsBeforeBonus.rfind('|');
        const auto lengthOfLastFrame = foundIndexOfBonus - foundIndexOfLastFrameStart - 1;
        const auto rollsInLastFrame = getbowlingCharacters().substr(foundIndexOfLastFrameStart + 1, lengthOfLastFrame);
        const auto numberOfBonusPoints = getbowlingCharacters().length() - (foundIndexOfBonus + 2);

        if (rollsInLastFrame[0] == 'X' &&
            numberOfBonusPoints == 2) {
            return true;
        }
        else if (rollsInLastFrame[1] == '/' &&
                 numberOfBonusPoints == 1) {
            return true;
        }
        else if (rollsInLastFrame[0] != 'X' &&
                 rollsInLastFrame[1] != '/' &&
                 numberOfBonusPoints == 0) {
            return true;
        }
    }
    return false;
}

bool SingleGame::isGameNotStarted()
{
    return getbowlingCharacters().empty();
}

void SingleGame::checkGameStatus()
{
    if (isGameNotStarted()) {
        gameStatus_ = SingleGame::GameStatus::NOT_STARTED;
    }
    else if (isGameFinished()) {
        gameStatus_ = SingleGame::GameStatus::FINISHED;
    }
    else {
        gameStatus_ = SingleGame::GameStatus::IN_PROGRESS;
    }
}

bool SingleGame::isStrike(size_t firstInFrame)
{
    return (rolls_[firstInFrame] == 10);
}

bool SingleGame::isSpare(size_t firstInFrame)
{
    if (((firstInFrame + 1) < rolls_.size())) {
        return ((rolls_[firstInFrame] + rolls_[firstInFrame + 1]) == 10);
    }

    return false;
}

size_t SingleGame::getBonusPointsForStrike(size_t firstInFrame)
{
    const auto numberOfRollsInGame = rolls_.size();
    size_t bonusPoints{};

    if ((firstInFrame + 1) < numberOfRollsInGame) {
        bonusPoints += rolls_[firstInFrame + 1];
    }
    if ((firstInFrame + 2) < numberOfRollsInGame) {
        bonusPoints += rolls_[firstInFrame + 2];
    }

    return bonusPoints;
}

size_t SingleGame::getBonusPointsForSpare(size_t firstInFrame)
{
    const auto numberOfRollsInGame = rolls_.size();
    size_t bonusPoints{};

    if ((firstInFrame + 2) < numberOfRollsInGame) {
        bonusPoints += rolls_[firstInFrame + 2];
    }
    return bonusPoints;
}

size_t SingleGame::getPointsForRegularGame(size_t firstInFrame)
{
    const auto numberOfRollsInGame = rolls_.size();
    size_t bonusPoints{};

    bonusPoints += rolls_[firstInFrame];
    if ((firstInFrame + 1) < numberOfRollsInGame) {
        bonusPoints += rolls_[firstInFrame + 1];
    }

    return bonusPoints;
}

void SingleGame::countScore()
{
    size_t score{};
    size_t firstInFrame{};
    const auto numberOfRollsInGame = rolls_.size();

    for (size_t i = 0; i < 10 && firstInFrame < numberOfRollsInGame; ++i) {
        if (isStrike(firstInFrame)) {
            score += 10 + getBonusPointsForStrike(firstInFrame);
            firstInFrame++;
        }
        else if (isSpare(firstInFrame)) {
            score += 10 + getBonusPointsForSpare(firstInFrame);
            firstInFrame += 2;
        }
        else {
            score += getPointsForRegularGame(firstInFrame);
            firstInFrame += 2;
        }
    }
    score_ = score;
}

void SingleGame::setRolls(std::size_t point)
{
    rolls_.push_back(point);
}

void SingleGame::makePointsFromSigns()
{
    const size_t MAXPOINT = 10;
    const size_t NOPOINT = 0;

    for (auto sign : getbowlingCharacters()) {
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

std::ostream& operator<<(std::ostream& os, const SingleGame& singleGame)
{
    os << singleGame.getPlayerName() << " " << singleGame.getScore() << '\n';
    return os;
}
