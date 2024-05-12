#include "PrefixMatcher.h"

#include <iostream>
#include <vector>


int PrefixMatcher::selectRouter(string networkAddress) {  // return the router with the longest matching prefix
    std::string prefix = addresses.prefixMatch(networkAddress);

    /*string longest = results[0];
    for(int i = 0; i < results.size(); i++) {
        if(results[i] > longest) {
            longest = results[i];
        }
    } */

    //std::cout << prefix << std::endl;

    return routers[prefix]; 
}

void PrefixMatcher::insert(string address, int routerNumber) { // add a router address

    addresses.addAddress(address);
    pair<string, int> map (address, routerNumber);
    routers.insert(map);

}