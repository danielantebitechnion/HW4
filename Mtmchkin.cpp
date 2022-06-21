#include "Mtmchkin.h"
#include "Exception.h"
#include <fstream>
using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::unique_ptr;
using std::stoi;
using std::getline;
using std::move;



int Mtmchkin::m_numberOfRounds = 1;
int Mtmchkin::m_amountOfLosers = 0;
int Mtmchkin::m_amountOfWinners = 0;
int Mtmchkin::m_numberOfPlayers = 0;

Mtmchkin::Mtmchkin(const string fileName){
    printStartGameMessage();
    checkFile(fileName);
    m_numberOfPlayers = initializeTeamSize();
    insertPlayers(m_numberOfPlayers);
    for(int i=0;i<MAXIMUM_AMOUNT_OF_PLAYERS;++i){
        m_playersRank[i] = i;
        m_isInGame.push_back(true);
    }
}

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
        throw DeckFileFormatError(amountOfCards+1);
    }
    if(amountOfCards < MINIMUM_AMOUNT_OF_CARDS){
        throw DeckFileInvalidSize();
    }
}

int Mtmchkin::initializeTeamSize() const{
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
    int addedPlayers = 0;
    string str;
    string playerName;
    string playerClass;
    while(addedPlayers < teamSize){
        printInsertPlayerMessage();
        getline(cin,str);
        if(str.find(SPACE_CHAR) == str.npos){//no space char
            playerName = str;
        }
        else{
            playerName = str.substr(0,str.find(SPACE_CHAR));
            playerClass = str.substr(str.find(SPACE_CHAR)+1);
        }
        if(checkName(playerName)){
            if(createPlayer(playerName,playerClass)){
                ++addedPlayers;
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
        unique_ptr<Player> newPlayer (new Fighter(playerName));
        m_playersInGame.push_back(move(newPlayer));
    }
    else if(ROGUE_STR == playerClass){
        unique_ptr<Player> newPlayer (new Rogue(playerName));
        m_playersInGame.push_back(move(newPlayer));
    }
    else if(WIZARD_STR == playerClass){
        unique_ptr<Player> newPlayer (new Wizard(playerName));
        m_playersInGame.push_back(move(newPlayer));
    }
    else{
        return false;
    }
    return true;

}

bool Mtmchkin::checkName(string playerName) const{
    if(playerName.length() <= MAX_PLAYER_NAME_LENGTH && playerName.length()> 0){
        int length = playerName.length();
        for(int i=0; i< length;++i){
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
        unique_ptr<Card> newCard (new Goblin());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == VAMPIRE_STR){
        unique_ptr<Card> newCard (new Vampire());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == DRAGON_STR){
        unique_ptr<Card> newCard (new Dragon());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == BARFIGHT_STR){
        unique_ptr<Card> newCard (new Barfight());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == FAIRY_STR){
        unique_ptr<Card> newCard (new Fairy());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == PITFALL_STR){
        unique_ptr<Card> newCard (new Pitfall());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == TREASURE_STR){
        unique_ptr<Card> newCard (new Treasure());
        m_cardsDeque.push_back(move(newCard));
    }
    else if(cardString == MERCHANT_STR){
        unique_ptr<Card> newCard (new Merchant());
        m_cardsDeque.push_back(move(newCard));
    }
    else{
        throw DeckFileFormatError(row);
    }   
}

int Mtmchkin::getNumberOfRounds() const{
    return m_numberOfRounds;
}

bool Mtmchkin::isGameOver() const{
    if(m_numberOfRounds > MAXIMUM_NUMBER_OF_ROUNDS){
        return true;
    }
    for(int i=0; i<m_numberOfPlayers;++i){
        if(m_isInGame[i]){
            return false;
        }
    }
    return true;
}

void Mtmchkin::updateGame(){
    int lostInRound = 0;
    int wonInRound = 0;
    for(int i=m_amountOfWinners;i<m_numberOfPlayers-m_amountOfLosers;++i){
        if(m_isInGame.at(i)){
            if(m_playersInGame.at(i)->isKnockedOut()){
                m_isInGame.at(i) = false;
                for(int j=i;j<m_numberOfPlayers-m_amountOfLosers-1-lostInRound;++j){
                    swap(m_playersRank[j],m_playersRank[j+1]);
                }
                ++lostInRound;
            }
            if(m_playersInGame.at(i)->getLevel() == MAX_LEVEL)
            {
                m_isInGame.at(i) = false;
                for(int j=i;j>m_amountOfWinners-wonInRound+1;--j){
                    swap(m_playersRank[j],m_playersRank[j-1]);
                }
                ++wonInRound;
            }
        }
    }
    m_amountOfLosers += lostInRound;
    m_amountOfWinners += wonInRound;
}

void Mtmchkin::playRound(){
    printRoundStartMessage(m_numberOfRounds);
    for(int i=0;i<m_numberOfPlayers;++i){
        if(m_isInGame.at(i)){
            printTurnStartMessage(m_playersInGame[i]->getName());
            m_cardsDeque.front()->applyEncounter(*m_playersInGame[i]);
            m_cardsDeque.push_back(move(m_cardsDeque.front()));
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

