#include <string>
#include <array>
#include <utility>

class Score {
public:
    void addResult(size_t throwResult);
    uint16_t getScore();
    std::string resultsToString();

private:
    static constexpr uint8_t maxOneThrowPoints_ {10};
    static constexpr uint8_t bonusTurn_ {10};
    bool frameEnd_ {false};
    uint8_t currentFrame_ {0};
    uint16_t finalScore_ {0};
    std::array<std::pair<uint8_t, uint8_t>, 11> result_ {};
    std::string throwResultToString(uint8_t ture, uint8_t throwInTurn);
};