#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void printVect(std::vector<int> list) {

    RecursiveBinarySearch r;

    if(r.search(list, 1)) {
        std::cout << "true ";
    }
    else {
        std::cout << "false ";
    }

    for(int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    //collect input
    std::vector<int> input;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream os(line);
    int i;
    while(os >> i) {
        input.push_back(i);
    }

    QuickSort q;
    std::vector<int> sortedList = q.sort(input);

    printVect(sortedList);

}