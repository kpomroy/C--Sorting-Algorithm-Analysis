#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "printVec.h"

template<typename Comparable>
void selectionSort(vector<Comparable> vec, int &reads, int &writes) {
    int swapIndex, i, minIndex;
    Comparable temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            if (vec[i] < vec[minIndex]) { // 2 reads
                // We have a new minimum
                minIndex = i;
            }
            //two reads line 14
            reads += 2;
        }
        // Swap min value into swapIndex spot in vector
        temp = vec[swapIndex]; // 1 read, 1 write
        vec[swapIndex] = vec[minIndex]; // 1 read, 1 write
        vec[minIndex] = temp; // 1 read, 1 write
        reads += 3;
        writes += 3;
//        printVec(vec);
    }
}

#endif
