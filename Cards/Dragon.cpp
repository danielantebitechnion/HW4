#include "../utilities.h"
#include "Dragon.h"
using std::string;

Dragon::Dragon ()
:
    Battle(DRAGON_STR, DRAGON_FORCE, DRAGON_COINS)
{

}

void Dragon::printInfo (std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    printMonsterDetails(os, this->m_force, 0,
    this->m_coins, true);
    printEndOfCardDetails(os);
}

void Dragon::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= this->m_force) // Player won
    {
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_cardName);
    }
    else // if Dragon won
    {
        player.damage(player.getHP());
        printLossBattle(player.getName(), this->m_cardName);
    }
}