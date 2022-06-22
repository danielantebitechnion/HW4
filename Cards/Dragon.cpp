#include "../utilities.h"
#include "Dragon.h"
using std::string;

Dragon::Dragon ()
:
    Battle(DRAGON_STR, DRAGON_FORCE, DRAGON_COINS, DFLT_MAX_HP)
{

}

void Dragon::printInfo (std::ostream& os) const
{
    printCardDetails(os, this->m_cardName);
    printMonsterDetails(os, this->m_force, 0,
    this->m_coins, true);
    printEndOfCardDetails(os);
}