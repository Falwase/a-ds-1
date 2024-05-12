#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

#include "Trie.h"

using namespace std;

class Autocomplete {
private:
    Trie trie;
public:
    vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord
    void insert(string word); // add a word to the known words
};

#endif