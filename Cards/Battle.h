#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card
{
    public:

        Battle (const std::string cardName, int force, int coins,
        int damage);

        virtual void printInfo(std::ostream& os) const override;
        
        virtual void applyEncounter(Player& player) const override;

        const std::string getName() const;

        const int getForce () const;

        const int getCoins () const;

        const int getDamage () const;

    protected:

        int m_force;

        int m_coins;

        int m_damage;
};

#endif // EX4_BATTLE_H