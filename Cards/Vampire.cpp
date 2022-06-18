#include "../utilities.h"
#include "Vampire.h"
using std::string;

Vampire::Vampire ()
:
    Battle(VAMPIRE_STR, VAMPIRE_FORCE, VAMPIRE_COINS),
    m_damage(VAMPIRE_DAMAGE)
{

}

void Vampire::printInfo (std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    printMonsterDetails(os, this->m_force, this->m_damage,
    this->m_coins);
    printEndOfCardDetails(os);
}

void Vampire::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= this->m_force) // Player won
    {
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_cardName);
    }
    else // if Vampire won
    {
        player.damage(this->m_damage);
        player.loseForce(VAMPIRE_PLAYER_LOST_FORCE);
        printLossBattle(player.getName(), this->m_cardName);
    }
}