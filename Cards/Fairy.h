#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

const int FAIRY_HEAL = 10;

class Fairy : public Card
{
    public:

        Fairy ();

        void applyEncounter(Player& player) const override;

    private:

        // nothing
};

#endif // EX4_FAIRY_H