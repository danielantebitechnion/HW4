#include "Fighter.h"
using std::string;

Fighter::Fighter (const string name)
:
    Player(name),
    m_job(FIGHTER_STR)
{

}

const int Fighter::getAttackStrength ()
{
    int attackStrength = (this->m_force * TWICE) + this->m_level;
    return attackStrength;
}

const string Fighter::getJob () const
{
    return this->m_job;
}