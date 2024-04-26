
#include "Node.h"

Node::Node(int data) {

    this->data = data;
}

//getter functions
int Node::getData() {
    return this->data;
}
Node* Node::getLink() {
    return this->link;
}

//setter functions
void Node::setLink(Node* link) {
    this->link = link;
}
void Node::setData(int data) {
    this->data = data;
}