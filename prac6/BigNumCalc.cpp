
#include "BigNumCalc.h"
#include <iostream>

//resulting string has the least significant digit first
std::list<int> BigNumCalc::buildBigNum(std::string numString) {

    std::list<int> l;

    for(int i = 0; i < numString.length(); i++) {

        l.push_front(numString[i] - '0');
    }

    while(l.back() == 0) {
        l.pop_back();
    }

    return l;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {

    int carry = 0;
    int digit;
    std::list<int>::iterator it1 = num1.begin();
    std::list<int>::iterator it2 = num2.begin();

    std::list<int> sum;

    int val1;
    int val2;
    bool numend1 = false;
    bool numend2 = false;
    while(!(numend1 && numend2) || carry) {

        //if beyond max digit, set val to 0
        if(!numend1) {
            val1 = *it1;
        }
        if(!numend2) {
            val2 = *it2;
        }

        //compute val to append to sum and carry to add to next val
        int val = val1 + val2 + carry;
        carry = 0;
        digit = val % 10;
        sum.push_back(digit);
        carry = val / 10;

        //iterate both lists and update numend values
        it1++;
        if(it1 == num1.end()) {
            numend1 = true;
            val1 = 0;
        }
        it2++;
        if(it2 == num2.end()) {
            numend2 = true;
            val2 = 0;
        }
    }

    sum.reverse();
    return sum;
}

//assumes num1 >= num2
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {

    int digit;
    std::list<int>::iterator it1 = num1.begin();
    std::list<int>::iterator it2 = num2.begin();

    std::list<int> diff;

    int val1;
    int val2;
    bool numend1 = false;
    bool numend2 = false;
    while(!(numend1 && numend2)) {

        //if beyond max digit, set val to 0
        if(!numend1) {
            val1 = *it1;
        }
        if(!numend2) {
            val2 = *it2;
        }

        digit = val1 - val2;
        if(digit < 0) {
            it1++;
            *it1 = *it1 - 1;
            it1--;
            digit += 10;
        }
        diff.push_back(digit);

        //iterate both lists and update numend values
        it1++;
        if(it1 == num1.end()) {
            numend1 = true;
            val1 = 0;
        }
        it2++;
        if(it2 == num2.end()) {
            numend2 = true;
            val2 = 0;
        }
    }

    diff.reverse();
    return diff;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    int digit;
    int carry = 0;
    std::list<int>::iterator it1 = num1.begin();

    std::list<int> mult;

    int val1;
    int val2 = num2.front();
    bool numend1 = false;
    while(!numend1 || carry) {

        //if beyond max digit, set val to 0
        if(!numend1) {
            val1 = *it1;
        }

        int val = val1 * val2 + carry;
        digit = val % 10;
        mult.push_back(digit);
        carry = val / 10;

        //iterate both lists and update numend values
        it1++;
        if(it1 == num1.end()) {
            numend1 = true;
            val1 = 0;
        }
    }

    mult.reverse();
    return mult;
}