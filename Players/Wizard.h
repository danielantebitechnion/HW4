#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard : public Player
{
    public:
        
        Wizard (const std::string name);

        /**
        * Increases twice the HP of Player:
        *
        * @param HPToAdd - the desired value to add to the HP.
        * @return
        *      void
        */
        void heal (int HPToAdd) override;

        const std::string getJob() const override;
    
    private:

        std::string m_job;
};

#endif //EX4_WIZARD_H