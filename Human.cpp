#include "Human.h"
#include "Player.h"

Human::Human() {
    name = "Human";
}

Human::Human(std::string n) {
    name = n;
}

Move* Human::makeMove( ) {
    std::string choice;
    std::cout << "Enter move: ";
    std::cin >> choice;

    return new Move(choice);
}