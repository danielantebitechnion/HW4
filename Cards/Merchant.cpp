#include "../utilities.h"
#include "Merchant.h"
using std::string;
using std::cin;
using std::cout;
using std::getline;

Merchant::Merchant ()
:
    Card(MERCHANT_STR)
{

}
/*
void Merchant::applyEncounter (Player& player) const
{
    int input = 0,price = 0;
    bool choseAction = false;
    printMerchantInitialMessageForInteractiveEncounter(cout,player.getName(), player.getCoins());
    string str;
    if(player.getCoins() < HEALTH_POTION_PRICE){
        printMerchantInsufficientCoins(cout);
    }
    else{
        getline(cin,str);
        while(!choseAction){
            if(str.length() == 1 && isdigit(str[0]) &&  stoi(str)>= LEAVE && stoi(str) <= FORCE_BOOST){
                input = stoi(str);
                choseAction = true;
                if (input == LEAVE)
                {
                    price = 0;
                }
                else if (input == HEALTH_POTION)
                {
                    if(player.getCoins() >= HEALTH_POTION_PRICE){
                        player.pay(HEALTH_POTION_PRICE);
                        player.heal(1);
                        price = HEALTH_POTION_PRICE;
                    }
                    else{
                        printMerchantInsufficientCoins(cout);
                    }
                }
                else{ // input == FORCE_BOOST
                    if(player.getCoins() >= FORCE_BOOST_PRICE){
                        player.pay(FORCE_BOOST_PRICE);
                        player.buff(1);
                        price = FORCE_BOOST_PRICE;
                    }
                    else{
                        printMerchantInsufficientCoins(cout);
                    }
                }
            }
            else{
                printInvalidInput();
                getline(cin,str);
            }
        }
    }
    printMerchantSummary(cout, player.getName(), input, price);  
}
*/

void Merchant::applyEncounter (Player& player) const
{
    int input = 0,price = 0;
    bool choseAction = false;
    printMerchantInitialMessageForInteractiveEncounter(cout,player.getName(), player.getCoins());
    string str;
    getline(cin,str);
    while(!choseAction){
        if(str.length() == 1 && isdigit(str[0]) &&  stoi(str)>= LEAVE && stoi(str) <= FORCE_BOOST){
            input = stoi(str);
            choseAction = true;
            if (input == HEALTH_POTION)
            {
                if(player.getCoins() >= HEALTH_POTION_PRICE){
                    player.pay(HEALTH_POTION_PRICE);
                    player.heal(1);
                    price = HEALTH_POTION_PRICE;
                }
                else{
                    printMerchantInsufficientCoins(cout);
                }
            }
            else if(input == FORCE_BOOST){
                if(player.getCoins() >= FORCE_BOOST_PRICE){
                    player.pay(FORCE_BOOST_PRICE);
                    player.buff(1);
                    price = FORCE_BOOST_PRICE;
                }
                else{
                    printMerchantInsufficientCoins(cout);
                }
            }
        }
        else{
            printInvalidInput();
            getline(cin,str);
        }
    }
    printMerchantSummary(cout, player.getName(), input, price);  
}