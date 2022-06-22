#include "../utilities.h"
#include "Battle.h"
using std::string;

Battle::Battle (const string cardName, int force, int coins, int damage)
:
    Card(cardName),
    m_force (force),
    m_coins (coins),
    m_damage (damage)
{

}

void Battle::printInfo (std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    printMonsterDetails(os, this->m_force, this->m_damage,
    this->m_coins);
    printEndOfCardDetails(os);
}

void Battle::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= this->m_force) // Player won
    {
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_cardName);
    }
    else // if Monster won
    {
        player.damage(this->m_damage);
        printLossBattle(player.getName(), this->m_cardName);
    }
}

const string Battle::getName () const
{
    return this->m_cardName;
}

const int Battle::getForce () const
{
    return this->m_force;
}

const int Battle::getCoins () const
{
    return this->m_coins;
}

const int Battle::getDamage () const
{
    return this->m_damage;
}