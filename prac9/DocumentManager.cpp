#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document d(name, id, license_limit);
    pair<int, Document> lib(id, d);
    library.insert(lib);

    pair<string, int> nl(name, id);
    nameList.insert(nl);
    return;
}

void DocumentManager::addPatron(int patronID) {
    userList.insert(patronID);
}

int DocumentManager::search(string name) {
    return nameList[name];
} // returns docid if name is in the document collection or 0 if the name is not in the collection

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if(!userList.count(patronID)) {
        return false;
    }
    if(library.count(docid)) {
        return false;
    }
    Document d = library.at(docid);
    return d.borrow(patronID);
} // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

void DocumentManager::returnDocument(int docid, int patronID) {
    Document d = library.at(docid);
    d.removePatron(patronID);
}