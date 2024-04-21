#include "QuickSort.h"

void printVect(std::vector<int> vect, int start, int end) {
    for(int i = start; i <= end; i++) {
        std::cout << vect[i] << std::endl;
    }
}

void swap(std::vector<int> &list, int a, int b) {
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

/*std::vector<int> QuickSort::sort(std::vector<int> list) {

    //partitionLimit array created with 0, list.size() - 1
    std::vector<int> part;
    part.push_back(list.size() - 1);
    part.push_back(0);

    int pivot, limit;
    int min, max;
    std::vector<int> tempVect;

    while(part.size() != 0) {
        //std::cout << "part vector:" << std::endl;
        //printVect(part, 0, part.size() - 1);
        //std::cout << std::endl;

        limit = -1;

        min = part.back();
        part.pop_back();
        max = part.back();
        part.pop_back();

        //pivot selection
        if(max - min >= 2) {
            pivot = min + 2;
        }
        else {
            pivot = min;
        }

        tempVect.clear();

        //std::cout << "pivot ";
        //std::cout << list[pivot] << std::endl;

        //create new partitions
        for(int i = min; i <= max; i++) {

            //swap elements larger than pivot with next element smaller than pivot
            if(list[i] >= list[pivot]) {
                tempVect.push_back(i);
            }
            else if(!tempVect.empty()) {
                int old = tempVect.front();
                tempVect.erase(tempVect.begin());

                int temp = list[old];
                list[old] = list[i];
                list[i] = temp;

                limit = old;

                //std::cout << "swapped!" << list[old] << list[i] << std::endl;

                //if pivot is being moved, update new pivot
                pivot = pivot == old ? i : pivot;

            }
        }

        //std::cout << max - min << std::endl;
        if(max - min <= 0) {
            continue;
        }

        //insert pivot into correct position
        int temp = list[pivot];
        list[pivot] = list[limit + 1];
        list[limit + 1] = temp;

        std::cout << "Partition" << std::endl;
        printVect(list, min, max);
        std::cout << std::endl;

        //add new partition indexes to part vector;
        //push back max first 
        part.push_back(max);
        part.push_back(limit + 2);
        //then min
        part.push_back(limit);
        part.push_back(min);
    }

    return list;
}*/

void doSort(std::vector<int> &list, int min, int max) {

    if(min >= max) {
        return;
    }

    int pivot;

    //assign pivot index
    if(max - min >= 2) {
        pivot = min + 2;
    }
    else {
        pivot = min;
    }

    swap(list, pivot, max);
    pivot = max;

    for(int i = min; i <= max; i++) {

        //for loop only executes if element higher than pivot is found
        //swaps element with next element that is lesser than the pivot
        for(int j = i; j <= max && list[i] > list[pivot]; j++) {

            if(list[i] > list[j]) {
                swap(list, i, j);

                break;
            }

            if(j == max) {
                swap(list, pivot, i);
                pivot = i;

                break;
            }
        }
    }

    doSort(list, min, pivot - 1);
    doSort(list, pivot + 1, max);
}

std::vector<int> QuickSort::sort(std::vector<int> list) {

    std::vector<int> sortedList;
    sortedList = list;

    doSort(sortedList, 0, list.size() - 1);

    return sortedList;
}