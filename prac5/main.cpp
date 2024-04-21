#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

#include <iostream>

void printVect(std::vector<int> vect) {
    for(int i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << std::endl;
    }
}

int main() {

    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(27);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(0);
    vect.push_back(3);
    vect.push_back(1);

    QuickSort b;

    //std::cout << "input vector:" << std::endl;
    //printVect(vect);

    std::cout << "sorted vector:" << std::endl;
    printVect(b.sort(vect));

    std::vector<int> orderedVect = b.sort(vect);

    RecursiveBinarySearch r;

    std::cout << "search result" << std::endl;
    std::cout << r.search(orderedVect, 0) << std::endl;
}