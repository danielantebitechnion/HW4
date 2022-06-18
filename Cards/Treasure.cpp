#include "../utilities.h"
#include "Treasure.h"
using std::string;

Treasure::Treasure ()
:
    Card(TREASURE_STR)
{

}

void Treasure::applyEncounter (Player& player) const
{
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}