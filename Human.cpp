#include "Human.h"
#include "Player.h"

Human::Human() {
    name = "Human";
}

Human::Human(std::string n) {
    name = n;
}

char Human::makeMove( ) {
    char choice;
    std::cout << "Enter move: ";
    std::cin >> choice;

    return choice;
}