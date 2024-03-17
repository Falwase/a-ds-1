
#include "Truckloads.h"
#include <iostream>

int Truckloads::numTrucks(int numCrates, int loadSize) {

    //std::cout << numCrates << std::endl;
    if (numCrates <= loadSize) {
        return 1;
    }

    return numTrucks((numCrates+1)/2, loadSize) + numTrucks(numCrates/2, loadSize);
}