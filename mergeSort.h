#ifndef MERGESORT_H
#define MERGESORT_H

#include "printVec.h"

template<typename Comparable>
void mergeSortRec(vector<Comparable> &vec, int startIndex, int endIndex, int &reads, int &writes) {
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Recursive calls for the left and right halves
    int centerIndex = (startIndex + endIndex) / 2;
    mergeSortRec(vec, startIndex, centerIndex, reads, writes);
    mergeSortRec(vec, centerIndex + 1, endIndex, reads, writes);

    // Merge
    vector<Comparable> temp;
    int leftIndex = startIndex;
    int rightIndex = centerIndex + 1;
    // While leftIndex and rightIndex are in bounds of their half
    while (leftIndex <= centerIndex && rightIndex <= endIndex) {
        if (vec[leftIndex] <= vec[rightIndex]) { // 2 reads
            temp.push_back(vec[leftIndex]); // 1 read, 1 write
            reads += 1;
            writes += 1;
            ++leftIndex;
        } else {
            temp.push_back(vec[rightIndex]); // 1 read, 1 write
            reads += 1;
            writes += 1;
            ++rightIndex;
        }
        reads += 2; // line 24
    }
    // Now one of the halves is empty and the other half has at least one element left to copy into temp
    while (leftIndex <= centerIndex) {
        temp.push_back(vec[leftIndex]); // 1 read, 1 write
        reads += 1;
        writes += 1;
        ++leftIndex;
    }
    while (rightIndex <= endIndex) {
        temp.push_back(vec[rightIndex]); // 1 read, 1 write
        reads += 1;
        writes += 1;
        ++rightIndex;
    }
    // Now everything between startIndex and endIndex is copied into temp
    // Copy everything from temp back into vec
    for (int i = 0; i < temp.size(); ++i) {
        vec[i + startIndex] = temp[i]; // 1 read, 1 write
        reads += 1;
        writes += 1;
    }

    printVec(vec);
}

template<typename Comparable>
void mergeSort(vector<Comparable> vec, int &reads, int &writes) {
    mergeSortRec(vec, 0, vec.size() - 1, reads, writes);
}

#endif
