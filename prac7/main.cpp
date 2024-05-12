
#include "PrefixMatcher.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    PrefixMatcher p;

    p.insert("1100110111", 1);
    p.insert("110011011", 2);
    p.insert("11001101", 3);

    cout << p.selectRouter("110011011101") << endl;
}