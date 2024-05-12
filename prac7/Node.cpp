
#include "Node.h"

Node::Node() {
    for(int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
    end = false;
}

void Node::setEnd(bool end) {
    this->end = end;
}
bool Node::getEnd() {
    return this->end;
}

Node* Node::getChild(int index) {
    return children[index];
}
void Node::setChild(int index, Node* newChild) {
    children[index] = newChild;
}