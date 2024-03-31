#include "Finder.h"

    using namespace std;

    /*vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;

        for(size_t i = 1; i <= s2.size(); i++) {
            size_t found = s1.find(s2.substr(0, i));
            if (found != string::npos) {
                result.push_back(found);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    } */

    vector<int> Finder::findSubstrings(string s1, string s2) {

        //Initialise result vector and set found to 0
        vector<int> result;
        size_t found = 0;

        for(size_t i = 1; i <= s2.size(); i++) {

            //Start substring from last found variable; this cuts down on unnecessary comparisons
            found = s1.find(s2.substr(0, i), found);

            //If one substring doesn't that means all subsequent substrings don't exist either. 
            //Hence for loop is broken upon reaching a non-existent substring
            if(found == string::npos) {
                break;
            }

            result.push_back(found);
        }

        //A difference in sizes between s2 and the result vector indicates early termination of loop
        //In such a case, fill remainder of result vector with -1
        for(size_t i = result.size(); result.size() != s2.size(); i++) {
            result.push_back(-1);
        }

        return result;
    }