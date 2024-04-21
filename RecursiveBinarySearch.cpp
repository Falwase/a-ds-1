#include "RecursiveBinarySearch.h" 

bool DoRBS(std::vector<int> list, int target, int min, int max) {

    if(min > max) {
        return false;
    }

    int midIndex = (max + min) / 2;

    if(target == list[midIndex]) {
        return true;
    }
    else if(target > list[midIndex]) {
        return DoRBS(list, target, midIndex + 1, max);
    }
    else {
        return DoRBS(list, target, min, midIndex - 1);
    }
}

bool RecursiveBinarySearch::search(std::vector<int> list, int target) {

    return DoRBS(list, target, 0, list.size() - 1);
}