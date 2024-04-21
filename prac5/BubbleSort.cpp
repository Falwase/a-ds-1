
#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    int n = list.size();
    bool swapped = false;
    int temp;
    std::vector<int> sortedList = list;

    for(int i = 0; i < n - 1; i++) {
        swapped = false;

        for(int j = 0; j < n - i; j++) {
            if(sortedList[j] > sortedList[j + 1]) {
                temp = sortedList[j + 1];
                sortedList[j + 1] = sortedList[j];
                sortedList[j] = temp;
                swapped = true;
            }
        }

        if(swapped == false) {
            break;
        }
    }

    return sortedList;
}