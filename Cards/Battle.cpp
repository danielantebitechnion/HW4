#include "Battle.h"
using std::string;

Battle::Battle (const string cardName, int force, int coins)
:
    Card(cardName),
    m_force (force),
    m_coins (coins)
{

}