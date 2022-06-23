#include "../utilities.h"
#include "Fairy.h"

Fairy::Fairy ()
:
    Card(FAIRY_STR)
{

}

void Fairy::applyEncounter (Player& player) const
{
    if (player.getJob() == WIZARD_STR)
    {
        player.heal(FAIRY_HEAL);
    }
    printFairyMessage(player.getJob() == WIZARD_STR);
}