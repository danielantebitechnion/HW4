#include "Wizard.h"
using std::string;

Wizard::Wizard (const string name)
:
    Player(name),
    m_job (WIZARD_STR)
{

}

void Wizard::heal (int HPToAdd)
{
    HPToAdd *= TWICE;
    if (HPToAdd < 0)
    {
        HPToAdd = 0;
    }
    if (this->m_HP < this->m_maxHP)
    {
        if (this->m_HP + HPToAdd >= this->m_maxHP)
        {
            this->m_HP = this->m_maxHP;
        }
        else // if this->m_HP + HPToAdd < this->m_maxHP
        {
            this->m_HP += HPToAdd;
        }
    }
}

const string Wizard::getJob() const
{
    return this->m_job;
}