#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_COINS = 2;
const int VAMPIRE_PLAYER_LOST_FORCE = 1;

class Vampire : public Battle
{
    public:

        Vampire ();

        void printInfo (std::ostream& os) const override;

        void applyEncounter(Player& player) const override;

    private:

        int m_damage;
};

#endif // EX4_VAMPIRE_H