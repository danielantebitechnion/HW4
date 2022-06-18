#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include "utilities.h"
#include <memory>
#include <map>

#include "Cards/Card.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"

#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"

const int MINIMUM_AMOUNT_OF_CARDS = 5;
const int MINIMUM_AMOUNT_OF_PLAYERS = 2;
const int MAXIMUM_AMOUNT_OF_PLAYERS = 6;
const char SPACE_CHAR = ' ';

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    private:
        
        std::vector<bool> m_isInGame; // true if player is still playing
        static int m_numberOfRounds; // count the number of rounds in game
        static int m_numberOfPlayers; // number of active players
        static int m_amountOfWinners;
        static int m_amountOfLosers;
        int m_playersRank[MAXIMUM_AMOUNT_OF_PLAYERS];
        std::deque<Card*> m_cardsDeque;
        std::vector<Player*> m_playersInGame;

        int initializeTeamSize() const;
        void createCard(const std::string cardString, int row);
        bool createPlayer(const std::string playerName, const std::string playerClass);
        void insertPlayers(int teamSize);
        void checkFile(const std::string fileName);
        void updateGame();
        bool checkName(std::string playerName) const;

        template <class T> void swap(T& a, T&b){
            T c(a);
            a=b;
            b=c;
        }
        
};



#endif /* MTMCHKIN_H_ */