#include "../utilities.h"
#include "Gang.h"
using std::vector;
using std::unique_ptr;
using std::move;

Gang::Gang (vector<unique_ptr<Battle>>&& monsters)
:
    Card(GANG_STR),
    m_monsters(move(monsters))
{

}

void Gang::applyEncounter (Player& player) const
{
    bool playerLost = false;
    for (vector<unique_ptr<Battle>>::const_iterator it = m_monsters.begin() ;
    it != m_monsters.end() ; ++it)
    {
        if (player.getAttackStrength() < it->get()->getForce() ||
        playerLost == true) // Monster won
        {
            player.damage(it->get()->getDamage());
            if (it->get()->getName() == VAMPIRE_STR)
            {
                player.loseForce(VAMPIRE_PLAYER_LOST_FORCE);
            }
            playerLost = true;
            printLossBattle(player.getName(), it->get()->getName());
        }
        else // if Player won
        {
            player.addCoins(it->get()->getCoins());
        }
    }
    if (playerLost == false)
    {
        player.levelUp();
        printWinBattle(player.getName(), this->m_cardName);
    }
}