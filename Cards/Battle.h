#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card
{
    public:

        Battle (const std::string cardName, int force, int coins);

    protected:

        int m_force;

        int m_coins;
};

#endif // EX4_BATTLE_H