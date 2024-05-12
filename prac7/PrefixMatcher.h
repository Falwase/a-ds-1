#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <unordered_map>
#include <string>

#include "Trie.h"

using namespace std;

class PrefixMatcher {
private:
    unordered_map<string, int> routers;
    Trie addresses;

public:
    int selectRouter(string networkAddress);  // return the router with the longest matching prefix
    void insert(string address, int routerNumber); // add a router address
};

#endif