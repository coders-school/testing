#pragma once

#include <string>
#include <vector>

class ArgumentParser {
public:
    enum class ArgumentNumber {
        FIRST_ARGUMENT,
        SECOND_ARGUMENT
    };

    ArgumentParser(int argc, const char** argv);
    ArgumentParser() = delete;

    std::string getArgument(const ArgumentNumber argumentNumber);
    size_t getArgumentsNumber() { return argumentsNumber_; };

private:
    std::vector<std::string> parsedArguments_{};
    size_t argumentsNumber_{};

    void parseArguments(const int argc, const char** argv);
};
