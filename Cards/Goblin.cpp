#include "../utilities.h"
#include "Goblin.h"
using std::string;

Goblin::Goblin ()
:
    Battle(GOBLIN_STR, GOBLIN_FORCE, GOBLIN_COINS),
    m_damage(GOBLIN_DAMAGE)
{

}

void Goblin::printInfo (std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    printMonsterDetails(os, this->m_force, this->m_damage,
    this->m_coins);
    printEndOfCardDetails(os);
}

void Goblin::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= this->m_force) // Player won
    {
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_cardName);
    }
    else // if Goblin won
    {
        player.damage(this->m_damage);
        printLossBattle(player.getName(), this->m_cardName);
    }
}