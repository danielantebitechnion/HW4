#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <string>
#include "utilities.h"

class Exception : public std::runtime_error{
    public:
    Exception(const std::string& what) : std::runtime_error(what){}
};

class DeckFileNotFound : public Exception{
    public:
    DeckFileNotFound() : Exception(std::string("Deck File Error: File not found"))
    {}
};

class DeckFileInvalidSize : public Exception{
    public:
    DeckFileInvalidSize() : Exception(std::string("Deck File Error: Deck size is invalid"))
    {}
};

class DeckFileFormatError : public Exception{
    public:
    DeckFileFormatError(int line) : Exception(std::string("Deck File Error: File format error in line " + std::to_string(line)))
    {}
};

#endif // EX4_EXCEPTION_H