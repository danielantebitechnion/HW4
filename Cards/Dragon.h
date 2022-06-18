#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

const int DRAGON_FORCE = 25;
const int DRAGON_COINS = 1000;

class Dragon : public Battle
{
    public:

        Dragon ();

        void printInfo(std::ostream& os) const override;
        
        void applyEncounter(Player& player) const override;

    private:

        // Nothing
};

#endif // EX4_DRAGON_H