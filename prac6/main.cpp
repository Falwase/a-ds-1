
#include "BigNumCalc.h"

#include <iostream>
#include <string>
#include <list>

void printList(std::list<int> l);

int main() {

    BigNumCalc b;
    std::list<int> l1 = b.buildBigNum("25");
    std::list<int> l2 = b.buildBigNum("5");

    printList(l1);
    printList(l2);
    printList(b.mul(l1, l2));
}

void printList(std::list<int> l) {

    for (std::list<int>::iterator i=l.begin(); i != l.end(); ++i) {
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
}