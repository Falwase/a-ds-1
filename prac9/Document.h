#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <unordered_set>

using namespace std;

class Document {
private:
    string name;
    int docid;
    int license_limit;
    unordered_set<int> borrowRecord;
public:
    Document(string name, int id, int license_limit);
    string getName();
    int getDocid();
    bool borrow(int patronID);
    bool removePatron(int patronID);
};

#endif