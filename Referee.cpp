#include "Referee.h" 
#include "Player.h"

Referee::Referee( ) {
    
} // constructor

Player* Referee::refGame(Player * player1, Player * player2) {
    
    Move* choice1 = player1->makeMove();
    Move* choice2 = player2->makeMove();
    
    if (choice1->ifWin(choice2)) {
        return player1;
    }
    else if (choice2->ifWin(choice1)) {
        return player2;
    }
    else {
        return nullptr;
    }
}
// returns the reference to the winning player