#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"
const int LEAVE = 0;
const int HEALTH_POTION = 1;
const int FORCE_BOOST = 2;
const int HEALTH_POTION_PRICE = 5;
const int FORCE_BOOST_PRICE = 10;

class Merchant : public Card
{
    public:

        Merchant ();

        void applyEncounter(Player& player) const override;

    private:

        // nothing
};

#endif // EX4_MERCHANT_H