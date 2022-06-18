#include "../utilities.h"
#include "Pitfall.h"
using std::string;

Pitfall::Pitfall ()
:
    Card(PITFALL_STR)
{

}

void Pitfall::applyEncounter (Player& player) const
{
    if (player.getJob() != ROGUE_STR)
    {
        player.damage(PITFALL_DAMAGE);
    }
    printPitfallMessage(player.getJob() == ROGUE_STR);
}