#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
#include <map>
#include <iostream>

const int DFLT_LEVEL = 1;
const int DFLT_COINS = 10;
const int DFLT_MAX_HP  = 100;
const int DFLT_FORCE  = 5;
const int MAX_LEVEL = 10;
const int TWICE  = 2;
const int MAX_PLAYER_NAME_LENGTH = 15;

const std::string FIGHTER_STR = "Fighter";
const std::string ROGUE_STR = "Rogue";
const std::string WIZARD_STR = "Wizard";

// enum playerNameMapIdxs
// {
//    FighterIDX,
//    RogueIDX,
//    WizardIDX
// };

// std::map <playerNameMapIdxs, std::string> playerNameMap =
// {
//    {FighterIDX, "Fighter"},
//    {RogueIDX, "Rogue"},
//    {WizardIDX, "Wizard"}
// };

class Player
{
    public:

        /**
        * The constructor of Player:
        *
        * @param name - The name of the player.
        */
        Player (const std::string name);
        
        /**
        * The destructor of Player.
        */
        ~Player ();
        
        /**
        * The copy constructor of Player:
        * 
        * @param player - Reference of the player.
        */
        Player (const Player &player);
        
        /**
        * The assignment operator of Player:
        *
        * @param player - Reference of the pplayer.
        */
        Player &operator= (const Player &player);
        
        /**
        * Increases the level of Player by one:
        * 
        * @return
        *      void
        */
        void levelUp ();
        
        /**
        * Returns the value in the field of level of Player:
        *
        * @return
        *      The level of Player.
        */
        const int getLevel () const;
        
        /**
        * Increases the force of Player by the given value:
        *
        * @param forceToAdd - the desired value to add to the force.
        * @return
        *      void
        */
        void buff (int forceToAdd);
        
        /**
        * Increases the HP of Player:
        *
        * @param HPToAdd - the desired value to add to the HP.
        * @return
        *      void
        */
        virtual void heal (int HPToAdd);
        
        /**
        * Decreases the HP of Player:
        *
        * @param HPToSubtract - the desired value to subtract from the HP.
        * @return
        *      void
        */
        void damage (int HPToSubtract);
        
        /**
        * Checks if Player is dead:
        * 
        * @return
        *      True if Player is dead, and False if Player is still alive.
        */
        const bool isKnockedOut ();
        
        /**
        * Increases the field of coins:
        *
        * @param coinsToAdd - the desired value to add to the coins.
        * @return
        *      void
        */
        virtual void addCoins (int coinsToAdd);
        
        /**
        * Decreases the coins (if possible):
        *
        * @param coinsToSubtract - how many coins to subtract to Player.
        * @return
        *      True if possible to decrease the coins, and False if not.
        */
        const bool pay (int coinsToSubtract);
        
        /**
        * Returns the sum of force and level:
        *
        * @return
        *      force + level
        */
        virtual const int getAttackStrength ();

        /**
        * Decreases the force of Player:
        *
        * @param forceToSubtract - desired value to subtract from force
        * @return
        *      void
        */
        void loseForce (int forceToSubtract);

        /**
        * Returns the value in the field of HP of Player:
        *
        * @return
        *      The HP of Player.
        */
        const int getHP () const;

        /**
        * Returns the string in the field of name of Player:
        *
        * @return
        *      The name of Player.
        */
        const std::string getName () const;

        /**
        * Returns the string in the field of job of Player:
        *
        * @return
        *      The job of Player.
        */
        virtual const std::string getJob () const = 0;

        /**
        * Returns the value in the field of coins of Player:
        *
        * @return
        *      The coins of Player.
        */
        int getCoins () const;

        class PlayerInvalidName {};

    protected:
        
        std::string m_name;
        
        int m_level;
        
        int m_force;
        
        int m_maxHP;
        
        int m_HP;
        
        int m_coins;
        
        friend std::ostream& operator<<(std::ostream&,const Player&);
};

#endif //EX4_PLAYER_H