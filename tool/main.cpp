#include "../Mtmchkin.h"

int main(){
    Mtmchkin game("C:\\Users\\user\\Desktop\\check.txt");
    while (!game.isGameOver())
    {
        game.playRound();
    }
    game.printLeaderBoard();
    
    return 0;
}