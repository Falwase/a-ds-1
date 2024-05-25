#include "Document.h"

Document::Document(string name, int id, int license_limit) {
    this->name = name;
    this->docid = id;
    this->license_limit = license_limit;
}

string Document::getName() {
    return this->name;
}

int Document::getDocid() {
    return this->docid;
}

bool Document::borrow(int patronID) {
    if(borrowRecord.size() == license_limit) {
        return false;
    }
    return borrowRecord.insert(patronID).second;
}

bool Document::removePatron(int patronID) {
    return borrowRecord.erase(patronID);
}