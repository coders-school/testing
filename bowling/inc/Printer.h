#pragma once

#include "printableData.hpp"
#include "printerStream.hpp"
#include "consoleStream.hpp"

#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include <stdexcept>


struct InvalidFileName : public std::invalid_argument{
    InvalidFileName() : std::invalid_argument("invalid name"){};
};







class FileStream : public PrinterStream{
public:
    FileStream(std::string filePath);
    ~FileStream(){
        file_->close();
        delete file_;
    }

    void print(std::string stream) override;
    void print(size_t value) override;

private:
    std::ofstream * file_;
};

class Printer{
public:
    Printer(PrinterStream * stream) : stream_(stream){};
    void print(std::vector<LaneStruct> lanes);

private:
    void printHeader(LaneStruct & lane);
    void print(std::string text);
    void print(size_t value);
    std::string parseStatus(const Status status);
    void printPlayers(LaneStruct & lane);
    void printPlayer(Player & player);

private:
    PrinterStream * stream_;
};
