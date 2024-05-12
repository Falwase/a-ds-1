#ifndef TRIE_H
#define TRIE_H

#include "Node.h"

#include <string>
#include <vector>

class Trie {

private:
    Node* root;
    void doAutocomplete(std::vector<std::string>& results, std::string option, Node* root);

public:
    Trie();

    void addWord(std::string word);
    bool findWord(std::string word, bool checkEnd);
    std::vector<std::string> autocomplete(std::string word);

    void addAddress(std::string address);
    std::string prefixMatch(std::string address);
};

#endif