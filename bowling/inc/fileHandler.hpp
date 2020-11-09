#pragma once

#include <fstream>
#include <string>

#include <stdexcept>

class WrongInput : public std::logic_error {
public:
    WrongInput(const std::string& err)
        : std::logic_error(err) {}
};

class FileHandler {
public:
    enum class FileAccess {
        INPUT,
        OUTPUT
    };

    FileHandler(std::string fileName, FileAccess fileAccess);
    FileHandler() = delete;
    ~FileHandler();

    bool isFileOpened() const { return fileStream_.is_open(); };
    std::string readLine();
    bool write(std::string dataToWrite);

private:
    std::string fileName_{};
    FileAccess fileAccess_{FileAccess::INPUT};
    std::fstream fileStream_{};
};
