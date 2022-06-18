#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

const int PITFALL_DAMAGE = 10;

class Pitfall : public Card
{
    public:

        Pitfall ();

        void applyEncounter(Player& player) const override;

    private:

        // nothing
};

#endif // EX4_PITFALL_H