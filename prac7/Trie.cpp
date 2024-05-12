
#include "Trie.h"

#include <iostream>
#include <algorithm>

Trie::Trie() {
    this->root = new Node();
}

void Trie::addWord(std::string word) {
    Node* temp = root;

    for(int i = 0; i < word.length(); i++) {

        //find letter and find place in alphabet as int
        char letter = toupper(word[i]);
        int place = (int)letter - (int)'A';

        //if corresponding child is null, create node
        if(temp->getChild(place) == nullptr) {
            Node* newChild = new Node();
            temp->setChild(place, newChild);
        }

        //traverse to next node
        temp = temp->getChild(place);

        //if last letter, set node end to true
        if(i == word.length()-1) {
            temp->setEnd(true);
        }
    }
}

bool Trie::findWord(std::string word, bool checkEnd) {

    Node* temp = root;

    for(int i = 0; i < word.length(); i++) {
        //find letter and find place in alphabet as int
        char letter = toupper(word[i]);
        int place = (int)letter - (int)'A';

        if(temp->getChild(place) == nullptr) {
            return false;
        }

        temp = temp->getChild(place);

        //if checkEnd is true, check if Trie sets node end to true at end of word. if not, return false;
        if(i == word.length() - 1 && checkEnd && !(temp->getEnd())) {
            return false;
        }
    }

    return true;
}

std::vector<std::string> Trie::autocomplete(std::string word) {
    Node* temp = root;
    std::vector<std::string> results;

    transform(word.begin(), word.end(), word.begin(), ::toupper);

    //find node of last letter of word
    for(int i = 0; i < word.length(); i++) {
        //find letter and find place in alphabet as int
        char letter = toupper(word[i]);
        int place = (int)letter - (int)'A';

        if(temp->getChild(place) == nullptr) {
            return results;
        }

        temp = temp->getChild(place);
    }

    //call recursive doAutocorrect function
    for(int i = 0; i < 26; i++) {
        if(temp->getChild(i) != nullptr) {
            char newLetter = i + 'A';
            doAutocomplete(results, word + newLetter, temp->getChild(i));
        }
    }

    return results;
}

void Trie::doAutocomplete(std::vector<std::string>& results, std::string option, Node* root) {

    if(root->getEnd()) {
        results.push_back(option);
    }

    //iterate through all children of Node. If any are open, call function again
    for(int i = 0; i < 26; i++) {
        if(root->getChild(i) != nullptr) {
            char newLetter = i + 'A';
            doAutocomplete(results, option + newLetter, root->getChild(i));
        }
    }
}

void Trie::addAddress(std::string address) {
    Node* temp = root;

    for(int i = 0; i < address.length(); i++) {

        //find letter and find place in alphabet as int
        int bit = address[i] - '0';

        //if corresponding child is null, create node
        if(temp->getChild(bit) == nullptr) {
            Node* newChild = new Node();
            temp->setChild(bit, newChild);
        }

        //traverse to next node
        temp = temp->getChild(bit);

        //if last letter, set node end to true
        if(i == address.length()-1) {
            temp->setEnd(true);
        }
    }
}

std::string Trie::prefixMatch(std::string address) {
    Node* temp = root;
    std::string prefix;

    for(int i = 0; i < address.length(); i++) {
        //find letter and find place in alphabet as int
        int bit = address[i] - '0';

        if(temp->getChild(bit) == nullptr) {
            //std::cout << prefix << std::endl;
            return prefix;
        }

        temp = temp->getChild(bit);
        if(temp->getEnd()) {
            prefix = address.substr(0, i+1);
            std::cout << prefix << std::endl;
        }
    }

    return prefix;
}

