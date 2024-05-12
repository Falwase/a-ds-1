
#include "Autocomplete.h"

vector<string> Autocomplete::getSuggestions(string partialWord) {  // return the known words that start with partialWord

    return trie.autocomplete(partialWord);
}

void Autocomplete::insert(string word) { // add a word to the known words
    trie.addWord(word);
}