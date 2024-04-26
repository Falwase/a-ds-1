#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {

private:
    Node* head;

public:
    //Constructors and destructors
    LinkedList();
    LinkedList(int* array, int len);
    ~LinkedList();

    //Member functions
    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos);
    int search(int target);
    void printList(); 
};

#endif