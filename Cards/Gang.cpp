#include "../utilities.h"
#include "Gang.h"
#include "Goblin.h"
using std::vector;

Gang::Gang (const vector<Battle> monsters)
:
    Card(GANG_STR),
    m_monsters(monsters)
{

}

void Gang::applyEncounter (Player& player) const
{
    bool playerLost = false;
    for (vector<Battle>::const_iterator it = m_monsters.begin() ;
    it != m_monsters.end() ; ++it)
    {
        if (player.getAttackStrength() < it->getForce() ||
        playerLost == true) // Monster won
        {
            player.damage(it->getDamage());
            if (it->getName() == VAMPIRE_STR)
            {
                player.loseForce(VAMPIRE_PLAYER_LOST_FORCE);
            }
            playerLost = true;
            printLossBattle(player.getName(), it->getName());
        }
        else // if Player won
        {
            player.addCoins(it->getCoins());
        }
    }
    if (playerLost == false)
    {
        player.levelUp();
        printWinBattle(player.getName(), this->m_cardName);
    }
}