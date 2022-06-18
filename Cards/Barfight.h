#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

const int BARFIGHT_DAMAGE = 10;

class Barfight : public Card
{
    public:

        Barfight ();

        void applyEncounter(Player& player) const override;

    private:

        // nothing
};

#endif // EX4_BARFIGHT_H