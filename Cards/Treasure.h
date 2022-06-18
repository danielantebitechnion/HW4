#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

const int TREASURE_COINS = 10;

class Treasure : public Card
{
    public:

        Treasure ();

        void applyEncounter(Player& player) const override;

    private:

        // nothing
};

#endif // EX4_TREASURE_H