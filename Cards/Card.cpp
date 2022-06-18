#include "Card.h"
#include "../utilities.h"
using std::string;

Card::Card (const string cardName)
:
    m_cardName (cardName)
{}

void Card::printInfo(std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}