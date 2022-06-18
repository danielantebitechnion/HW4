#include "../utilities.h"
#include "Barfight.h"

Barfight::Barfight ()
:
    Card(BARFIGHT_STR)
{

}

void Barfight::applyEncounter (Player& player) const
{
    if (player.getJob() != FIGHTER_STR)
    {
        player.damage(BARFIGHT_DAMAGE);
    }
    printBarfightMessage(player.getJob() == FIGHTER_STR);
}