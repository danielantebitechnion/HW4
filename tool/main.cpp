#include "../Mtmchkin.h"
using std::cerr;
using std::endl;

int main(){
    try{
        Mtmchkin game("C:\\Users\\user\\Desktop\\deck.txt");
        while (!game.isGameOver())
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch(const DeckFileNotFound& e){
        cerr << e.what() << endl;
    }
    catch(const DeckFileFormatError& e){
        cerr << e.what() << endl;
    }
    catch(const DeckFileInvalidSize& e){
        cerr << e.what() << endl;
    }

    return 0;
}