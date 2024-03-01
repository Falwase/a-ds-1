#include "Human.h"

Human::Human() {
    this->name = "Human";
}

Human::Human(string name) {
    this->name = name;
}

char Human::makeMove( ) {
    char choice;
    std::cout << "Enter move: ";
    std::cin >> choice;

    return choice;
}