#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "Document.h"

#include <unordered_map>
#include <unordered_set>

using namespace std;

class DocumentManager {

private:
    unordered_map<int, Document> library;
    unordered_map<string, int> nameList;
    unordered_set<int> userList;

public:
    void addDocument(string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(string name); // returns docid if name is in the document collection or 0 if the name is not in the collection
    bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
    void returnDocument(int docid, int patronID);
};

#endif