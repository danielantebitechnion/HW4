#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

class Rogue : public Player
{
    public:

        Rogue (const std::string name);

        /**
        * Increases twice the field of coins:
        *
        * @param coinsToAdd - the desired value to add to the coins.
        * @return
        *      void
        */
        void addCoins (int coinsToAdd) override;

        const std::string getJob () const override;

    private:

        std::string m_job;
};

#endif //EX4_ROGUE_H