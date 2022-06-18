#include "../utilities.h"
#include "Merchant.h"
using std::string;
using std::cin;
using std::cout;

Merchant::Merchant ()
:
    Card(MERCHANT_STR)
{

}

void Merchant::applyEncounter (Player& player) const
{
    int input,price;
    bool choseAction = false;
    printMerchantInitialMessageForInteractiveEncounter(cout,player.getName(), player.getCoins());
    string str;
    cin >> str;
    while(!choseAction){
        if(str.length() == 1 && isdigit(str[0]) &&  stoi(str)>= LEAVE && stoi(str) <= FORCE_BOOST){
            input = stoi(str);
            if (input == LEAVE)
            {
                choseAction = true;
                price = 0;
            }
            else if (input == HEALTH_POTION)
            {
                if(player.getCoins() >= HEALTH_POTION_PRICE){
                    player.pay(HEALTH_POTION_PRICE);
                    player.heal(1);
                    price = HEALTH_POTION_PRICE;
                    choseAction = true;
                }
                else{
                    printMerchantInsufficientCoins(cout);
                    cin >> str;
                }
            }
            else{ // input == FORCE_BOOST
                if(player.getCoins() >= FORCE_BOOST_PRICE){
                    player.pay(FORCE_BOOST_PRICE);
                    player.buff(1);
                    price = FORCE_BOOST_PRICE;
                    choseAction = true;
                }
                else{
                    printMerchantInsufficientCoins(cout);
                    cin >> str;
                }
            }
        }
        else{
            printInvalidInput();
            cin >> str;
        }
    }
    printMerchantSummary(cout, player.getName(), input, price);  
}