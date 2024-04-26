
#include "LinkedList.h"

#include <limits>
#include <iostream>

LinkedList::LinkedList() {

    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {

    //initialise head
    Node* curr = new Node(array[0]);
    this->head = curr;

    //initialise other nodes
    for(int i = 1; i < len; i++) {
        Node* next = new Node(array[i]);
        curr->setLink(next);
        curr = next;
    }
}

LinkedList::~LinkedList() {
    Node* curr;
    Node* next;
    curr = head;

    while(curr != nullptr) {
        next = curr->getLink();
        delete curr;
        curr = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {

    Node* curr;
    curr = head;

    //insert at head
    if(pos <= 1) {
        
        head = new Node(newNum);
        head->setLink(curr);
        return;
    }

    Node* next;

    //find position in linked list
    for(int i = 0; i < pos - 2; i++) {
        
        next = curr->getLink();

        if(next == nullptr) {
            break;
        }

        curr = next;
    }

    next = new Node(newNum);
    next->setLink(curr->getLink());
    curr->setLink(next);

    return;
}

bool LinkedList::deletePosition(int pos) {

    if(pos < 1) {
        return false;
    }

    Node* curr = head;

    if(pos == 1) {
        head = curr->getLink();
        delete curr;
        return true;
    }

    for(int i = 1; i < pos - 1; i++) {

        if(curr == nullptr) {
            return false;
        }

        curr = curr->getLink();
    }

    Node* next = curr->getLink();

    if(next == nullptr) {
        return false;
    }

    curr->setLink(next->getLink());
    delete next;
    return true;
}

int LinkedList::get(int pos) {

    if(pos < 1) {
        return std::numeric_limits < int >::max();
    }

    Node* curr = head;
    for(int i = 1; i < pos; i++) {

        if(curr == nullptr) {
            return std::numeric_limits < int >::max();
        }

        curr = curr->getLink();
    }

    return curr->getData();
}

int LinkedList::search(int target) {

    Node* curr = head;
    int i = 1;
    while(true) {

        if(curr == nullptr) {
            return -1;
        }

        if(curr->getData() == target) {
            return i;
        }

        curr = curr->getLink();
        i++;
    }
}

void LinkedList::printList() {

    if(head == nullptr) {
        return;
    }

    Node* curr = head;
    std::cout << "[";
    while(true) {

        if(curr->getLink() == nullptr) {
            std::cout << curr->getData() << "]" << std::endl;
            return;
        }

        std::cout << curr->getData() << " ";

        curr = curr->getLink();
    }
}  