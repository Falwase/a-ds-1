#include "Referee.h"
#include "Computer.h"
#include "Human.h"
#include "Player.h"

int main() {

    Referee r = Referee();

    Human player = Human();

    Computer comp = Computer();

    r.refGame(&player, &comp);

    return 0;
};