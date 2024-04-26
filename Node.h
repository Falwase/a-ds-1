#ifndef NODE_H
#define NODE_H

class Node {

private:
    int data;
    Node* link;

public:
    Node(int data);

    //getter functions
    int getData();
    Node* getLink();

    //setter functions
    void setLink(Node* link);
    void setData(int data);
};

#endif