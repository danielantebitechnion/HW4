#ifndef EX4_DECK_EXCEPTION_H
#define EX4_DECK_EXCEPTION_H

#include <string>
#include "utilities.h"

class DeckException : public std::runtime_error
{
    public:

        DeckException (const std::string& what)
        :
        std::runtime_error(what)
        {}
};

class DeckFileNotFound : public DeckException
{
    public:

        DeckFileNotFound ()
        :
        DeckException(std::string("Deck File Error: File not found"))
        {}
};

class DeckFileInvalidSize : public DeckException
{
    public:

        DeckFileInvalidSize ()
        :
        DeckException(std::string("Deck File Error: Deck size is invalid"))
        {}
};

class DeckFileFormatError : public DeckException
{
    public:

        DeckFileFormatError (int line)
        :
        DeckException(std::string("Deck File Error: File format error in line " + std::to_string(line)))
        {}
};

#endif // EX4_DECK_EXCEPTION_H