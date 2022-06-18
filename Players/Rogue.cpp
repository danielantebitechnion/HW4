#include "Rogue.h"
using std::string;

Rogue::Rogue (const string name)
:
    Player(name),
    m_job (ROGUE_STR)
{
    
}

void Rogue::addCoins (int coinsToAdd)
{
    coinsToAdd *= TWICE;
    if (coinsToAdd < 0)
    {
        coinsToAdd = 0;
    }
    this->m_coins += coinsToAdd;
}

const string Rogue::getJob () const
{
    return this->m_job;
}