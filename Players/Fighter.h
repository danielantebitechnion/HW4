#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
    public:

        Fighter (const std::string name);
        
        /**
        * Returns the sum of force times two and level:
        *
        * @return
        *      (force * 2) + level
        */
        const int getAttackStrength () override;

        const std::string getJob () const override;

    private:

        std::string m_job;
};

#endif //EX4_FIGHTER_H