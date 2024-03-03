#include "Referee.h" 
#include "Player.h"

Referee::Referee( ) {}; // constructor

Player* Referee::refGame(Player * player1, Player * player2) {
    
    char choice = player1->makeMove();
    
    if (choice == 'P') {
        return player1;
    }

    else if (choice == 'S') {
        return player2;
    }

    else {
        return nullptr;
    }
}
// returns the reference to the winning player