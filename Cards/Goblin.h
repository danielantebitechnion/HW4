#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

const int GOBLIN_FORCE = 6;
const int GOBLIN_DAMAGE = 10;
const int GOBLIN_COINS = 2;

class Goblin : public Battle
{
    public:

        Goblin ();
        
        void printInfo (std::ostream& os) const override;

        void applyEncounter(Player& player) const override;

    private:

        int m_damage;
};

#endif // EX4_GOBLIN_H