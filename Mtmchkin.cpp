#include "Mtmchkin.h"
#include "Exception.h"
#include <fstream>
using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::unique_ptr;
using std::stoi;


int Mtmchkin::m_numberOfRounds = 0;
int Mtmchkin::m_amountOfLosers = 0;
int Mtmchkin::m_amountOfWinners = 0;
int Mtmchkin::m_numberOfPlayers = 0;

Mtmchkin::Mtmchkin(const string fileName){
    checkFile(fileName);
    m_numberOfPlayers = initializeTeamSize();
    insertPlayers(m_numberOfPlayers);
    for(int i=0;i<MAXIMUM_AMOUNT_OF_PLAYERS;++i){
        m_playersRank[i] = i;
        m_isInGame.push_back(true);
    }
};

void Mtmchkin::checkFile(const string fileName){
    int amountOfCards =0;
    ifstream source(fileName.c_str());
    if(!source){
        throw DeckFileNotFound();
    }
    try{
        string line;
        while (getline(source,line)){
            createCard(line,amountOfCards);
            ++amountOfCards;
        }
    }catch(const DeckFileFormatError& e){
        //m_cardsDeque.release();
        throw DeckFileFormatError(amountOfCards+1);
    }
    if(amountOfCards <= MINIMUM_AMOUNT_OF_CARDS){
        //m_cardsDeque.release();
        throw DeckFileInvalidSize();
    }
}

int Mtmchkin::initializeTeamSize() const{
    printStartGameMessage();
    string teamSize;
    while (true)
    {
        printEnterTeamSizeMessage();
        cin >> teamSize;
        if(teamSize.length() == 1 && isdigit(teamSize[0]))
        {
            int size = stoi(teamSize);
            if(size >= MINIMUM_AMOUNT_OF_PLAYERS && size <= MAXIMUM_AMOUNT_OF_PLAYERS)
            {
                 return size;
            }
        }
        printInvalidTeamSize();
    }
}

void Mtmchkin::insertPlayers(int teamSize){
    int players = 0;
    string str;
    string playerName;
    string playerClass;
    while(players < teamSize){
        printInsertPlayerMessage();
        fflush(stdin);
        getline(cin , str);
        if(str.find(SPACE_CHAR) == str.npos){//no space char
            playerName = str;
        }
        else{
            playerName = str.substr(0,str.find(SPACE_CHAR));
            playerClass = str.substr(str.find(SPACE_CHAR)+1);
        }
        if(checkName(playerName)){
            if(createPlayer(playerName,playerClass)){
                ++players;
            }
            else{
                printInvalidClass();
            }
        }
        else{
            printInvalidName();
        }
    }
}

bool Mtmchkin::createPlayer(const std::string playerName, const std::string playerClass)
{
    if(FIGHTER_STR == playerClass){
        m_playersInGame.push_back(new Fighter(playerName));
    }
    else if(ROGUE_STR == playerClass){
        m_playersInGame.push_back(new Rogue(playerName));;
    }
    else if(WIZARD_STR == playerClass){
        m_playersInGame.push_back(new Wizard(playerName));;
    }
    else{
        return false;
    }
    return true;

}

bool Mtmchkin::checkName(string playerName) const{
    if(playerName.length() <= MAX_PLAYER_NAME_LENGTH && playerName.length()> 0){
        for(int i=0; i< playerName.length();++i){
            if(!(isalpha(playerName[0]))){
                return false;
            }
        }
        return true;
    }
    return false;
}

void Mtmchkin::createCard(const string cardString,int row){

    if(cardString == GOBLIN_STR){
        m_cardsDeque.push_back(new Goblin());
    }
    else if(cardString == VAMPIRE_STR){
       m_cardsDeque.push_back(new Vampire());
    }
    else if(cardString == DRAGON_STR){
        m_cardsDeque.push_back(new Dragon());
    }
    else if(cardString == BARFIGHT_STR){
        m_cardsDeque.push_back(new Barfight());
    }
    else if(cardString == FAIRY_STR){
        m_cardsDeque.push_back(new Fairy());
    }
    else if(cardString == PITFALL_STR){
        m_cardsDeque.push_back(new Pitfall());
    }
    else if(cardString == TREASURE_STR){
        m_cardsDeque.push_back(new Treasure());
    }
    else if(cardString == MERCHANT_STR){
        m_cardsDeque.push_back(new Merchant());
    }
    else{
        throw DeckFileFormatError(row);
    }   
}

int Mtmchkin::getNumberOfRounds() const{
    return m_numberOfRounds;
}

bool Mtmchkin::isGameOver() const{
    bool isOver = false;
    for(int i=0; i<m_numberOfPlayers;++i){
        if(m_isInGame.at(i)){
            return false;
        }
    }
    return true;
}

void Mtmchkin::updateGame(){
    for(int i=m_amountOfWinners;i<m_numberOfPlayers-m_amountOfLosers;++i){
        if(m_isInGame.at(i)){
            if(m_playersInGame.at(i)->isKnockedOut()){
                m_isInGame.at(i) = false;
                for(int j=i;j<m_numberOfPlayers-m_amountOfLosers-1;++j){
                    swap(m_playersRank[j],m_playersRank[j+1]);
                }
                ++m_amountOfLosers;
            }
            if(m_playersInGame.at(i)->getLevel() == MAX_LEVEL)
            {
                m_isInGame.at(i) = false;
                for(int j=i;j>m_amountOfWinners+1;--j){
                    swap(m_playersRank[j],m_playersRank[j-1]);
                }
                ++m_amountOfWinners;
            }
        }
    }
}

void Mtmchkin::playRound(){
    printRoundStartMessage(m_numberOfRounds);
    for(int i=0;i<m_numberOfPlayers;++i){
        if(m_isInGame.at(i)){
            printTurnStartMessage(m_playersInGame[i]->getName());
            m_cardsDeque.front()->applyEncounter(*m_playersInGame[i]);
            m_cardsDeque.push_back(m_cardsDeque.front());
            m_cardsDeque.pop_front();
        }
    }
    updateGame();
    ++m_numberOfRounds;
    if(isGameOver()){
        printGameEndMessage();
    }

}

void Mtmchkin::printLeaderBoard() const{
    printLeaderBoardStartMessage();
    for(int i=0;i<m_numberOfPlayers;++i){
        printPlayerLeaderBoard(i+1,*m_playersInGame[m_playersRank[i]]);
    }
}
