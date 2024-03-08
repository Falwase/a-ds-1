#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"
#include <vector>

using namespace std;

class Referee
{

private:

public:
    Referee( ); // constructor
    Player* refGame(Player * player1, Player * player2);
    // returns the reference to the winning player  
};

#endif