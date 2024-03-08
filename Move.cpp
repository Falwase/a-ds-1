#include "Move.h"

Move::Move(std::string name) {

    //appends strings to matchups set according to selected move
    if (name == "Robot") {
        matchups.insert("Ninja");
        matchups.insert("Zombie");
    }
    else if (name == "Monkey") {
        matchups.insert("Ninja");
        matchups.insert("Robot");   
    }
    else if (name == "Pirate") {
        matchups.insert("Robot");
        matchups.insert("Monkey");
    }
    else if (name == "Ninja") {
        matchups.insert("Pirate");
        matchups.insert("Zombie");
    }
    else if (name == "Zombie") {
        matchups.insert("Pirate");
        matchups.insert("Monkey");
    }
    else if (name == "Rock") {
        matchups.insert("Scissors");
    }
    else if (name == "Paper") {
        matchups.insert("Rock");
    }
    else if (name == "Scissors") {
        matchups.insert("Paper");
    }
    
    this->moveName = name;
}

std::string Move::getName() {
    return this->moveName;
}

//checks if opponent's move matches any in the matchups set. If so, this player wins.
bool Move::ifWin(Move* opp) {
    
    if (matchups.count(opp->getName())) {
        return true;
    }

    return false;
}