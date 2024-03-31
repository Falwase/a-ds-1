#include "Finder.h"

int main() {

    Finder f = Finder();

    std::string s1 = "4634554567";
    std::string s2 = "45689";

    std::vector<int> result = f.findSubstrings(s1, s2);

    for(int i=0; i < result.size(); i++) {
        std::cout << result.at(i) << std::endl;
    }
}