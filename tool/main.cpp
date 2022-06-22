#include "../Mtmchkin.h"
using std::cerr;
using std::endl;

int main(){
    Mtmchkin game("C:\\Users\\user\\Desktop\\deck.txt");
    while (!game.isGameOver())
    {
        game.playRound();
    }
    game.printLeaderBoard();
    return 0;
}