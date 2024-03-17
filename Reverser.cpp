
#include "Reverser.h"

using namespace std;

int Reverser::reverseDigit(int value) {

    if (value < 0) {
        return -1;
    }

    if (value < 10) {
        return value;
    }

    int num = value % 10;

    int result = reverseDigit((value - num) / 10);

    int x = 10;
    while(x <= result) {
        x *= 10;
    }

    return (num * x) + result;
}

string Reverser::reverseString(string characters) {

    if (characters.length() < 0) {
        return "ERROR";
    }

    if (characters.length() <= 1) {
        return characters;
    }

    string letter;
    letter.push_back(characters.back());
    characters.pop_back();

    string result = reverseString(characters);

    return letter.append(result);
}