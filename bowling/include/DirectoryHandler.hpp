#pragma once

#include <string>
#include <vector>

class DirectoryHandler {
public:
    DirectoryHandler(const std::string directoryName)
        : directoryName_{directoryName} {
        processData();
    }

    std::vector<std::pair<int, std::vector<std::string>>> getDirectoryData() {
        return rawLanesData_;
    }

    void printData();

private:
    std::string directoryName_;
    std::vector<std::pair<int, std::vector<std::string>>> rawLanesData_;

    void processData();
};
