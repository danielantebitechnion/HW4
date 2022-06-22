#ifndef EX2_CARD_H
#define EX2_CARD_H

#include <string>
#include <map>
#include "../Players/Player.h"

const std::string BARFIGHT_STR = "Barfight";
const std::string DRAGON_STR = "Dragon";
const std::string FAIRY_STR = "Fairy";
const std::string GOBLIN_STR = "Goblin";
const std::string MERCHANT_STR = "Merchant";
const std::string PITFALL_STR = "Pitfall";
const std::string TREASURE_STR = "Treasure";
const std::string VAMPIRE_STR = "Vampire";
const std::string GANG_STR = "Gang";

const int DRAGON_FORCE = 25;
const int DRAGON_COINS = 1000;
const int GOBLIN_FORCE = 6;
const int GOBLIN_DAMAGE = 10;
const int GOBLIN_COINS = 2;
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_COINS = 2;
const int VAMPIRE_PLAYER_LOST_FORCE = 1;

class Card {

    public:

        /*
        * C'tor of Card class
        *
        * @param type - The type of the card.
        * @param stats - The numeral stats of the card.
        * @return
        *      A new instance of Card.
        */
        Card(const std::string cardName);

        /*
        * Handling the player's applyEncounter with the card:
        *
        * @param player - The player.
        * @return
        *      void
        */
        virtual void applyEncounter(Player& player) const = 0;

        virtual void printInfo(std::ostream& os) const;

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        Card(const Card&) = default;
        ~Card() = default;
        Card& operator=(const Card& other) = default;

        class DeckFileFormatError {};

    protected:

        std::string m_cardName;

        friend std::ostream& operator<<(std::ostream&, const Card& card);
};

#endif //EX2_Card_H