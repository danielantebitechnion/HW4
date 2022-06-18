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

// enum cardNameMapIdxs
// {
//    First,
//    BarfightIDX,
//    DragonIDX,
//    FairyIDX,
//    GoblinIDX,
//    MerchantIDX,
//    PitfallIDX,
//    TreasureIDX,
//    VampireIDX,
//    Last
// };

// std::map <cardNameMapIdxs, std::string> cardNameMap =
// {
//    {BarfightIDX, "Barfight"},
//    {DragonIDX, "Dragon"},
//    {FairyIDX, "Fairy"},
//    {GoblinIDX, "Goblin"},
//    {MerchantIDX, "Merchant"},
//    {PitfallIDX, "Pitfall"},
//    {TreasureIDX, "Treasure"},
//    {VampireIDX, "Vampire"}
// };

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

        friend std::ostream& operator<<(std::ostream&, const Card&);
};

#endif //EX2_Card_H