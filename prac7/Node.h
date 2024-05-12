#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node {

private:
    Node* children[26];
    bool end;
public:
    Node();

    void setEnd(bool end);
    bool getEnd();

    Node* getChild(int index);
    void setChild(int index, Node* newChild);
};

#endif