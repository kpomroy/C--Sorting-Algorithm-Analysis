#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
void bubbleSort(vector<Comparable> vec, int &reads, int &writes) {
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) { // 2 reads
                temp = vec[i]; // 1 read, 1 write
                vec[i] = vec[i+1]; // 1 read, 1 write
                vec[i+1] = temp; // 1 read, 1 write
                // Update haveSwapped
                haveSwapped = true;
                //3 reads lines 16, 17, 18
                reads += 3;
                //3 writes lines 16, 17, 18
                writes += 3;
            }
            //2 reads line 15
            reads += 2;
        }
        // Update numPasses
        ++numPasses;
        printVec(vec);
    }
}

#endif
