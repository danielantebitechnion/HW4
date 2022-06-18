#include "Player.h"
#include "../utilities.h"
using std::isalpha;
using std::string;
using std::endl;

Player::Player (const string name)
:
    m_name (name),
    m_level (DFLT_LEVEL),
    m_force (DFLT_FORCE),
    m_maxHP (DFLT_MAX_HP),
    m_HP (DFLT_MAX_HP),
    m_coins (DFLT_COINS)
{}

Player::~Player ()
{
    
}

Player::Player (const Player &player)
{
    this->m_name = player.m_name;
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHP = player.m_maxHP;
    this->m_HP = player.m_HP;
    this->m_coins = player.m_coins;
}

Player &Player::operator= (const Player &player)
{
    if (this == &player)
    {
        return *this;
    }
    this->m_name = m_name;
    this->m_level = player.m_level;
    this->m_force = player.m_force;
    this->m_maxHP = player.m_maxHP;
    this->m_HP = player.m_HP;
    this->m_coins = player.m_coins;
    return *this;
}

void Player::levelUp ()
{
    if (this->m_level < MAX_LEVEL)
    {
        ++this->m_level;
    }
}

const int Player::getLevel () const
{
    return this->m_level;
}

void Player::buff (int forceToAdd)
{
    if (forceToAdd < 0)
    {
        forceToAdd = 0;
    }
    this->m_force += forceToAdd;
}

void Player::heal (int HPToAdd)
{
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

void Player::damage (int HPToSubtract)
{
    if (HPToSubtract < 0)
    {
        HPToSubtract = 0;
    }
    if (this->m_HP > 0)
    {
        if (this->m_HP - HPToSubtract <= 0)
        {
            this->m_HP = 0;
        }
        else // this->m_HP - HPToSubtract > 0
        {
            this->m_HP -= HPToSubtract;
        }
    }
}

const bool Player::isKnockedOut ()
{
    if (this->m_HP <= 0)
    {
        return true;
    }
    // else
    return false;
}

void Player::addCoins (int coinsToAdd)
{
    if (coinsToAdd < 0)
    {
        coinsToAdd = 0;
    }
    this->m_coins += coinsToAdd;
}

const bool Player::pay (int coinsToSubtract)
{
    if (coinsToSubtract < 0)
    {
        coinsToSubtract = 0;
    }
    if (this->m_coins - coinsToSubtract >= 0)
    {
        this->m_coins -= coinsToSubtract;
        return true;
    }
    // else
    return false;
}

const int Player::getAttackStrength ()
{
    int attackStrength = this->m_force + this->m_level;
    return attackStrength;
}

void Player::loseForce (int forceToSubtract)
{
    if (forceToSubtract < 0)
    {
        forceToSubtract = 0;
    }
    if (this->m_force > 0)
    {
        if (this->m_force - forceToSubtract <= 0)
        {
            this->m_force = 0;
        }
        else // this->m_force - forceToSubtract > 0
        {
            this->m_force -= forceToSubtract;
        }
    }
}

const int Player::getHP () const
{
    return this->m_HP;
}

const string Player::getName () const
{
    return this->m_name;
}

int Player::getCoins () const
{
    return this->m_coins;
}

std::ostream& operator<<(std::ostream& os,const Player& player)
{
    printPlayerDetails (os, player.m_name.c_str(),
    player.getJob().c_str(), player.m_level, player.m_force, player.m_HP,
    player.m_coins);
    os << endl;
    return os;
}