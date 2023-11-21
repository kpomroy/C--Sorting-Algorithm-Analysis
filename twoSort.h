#ifndef PROJECT4_TWOSORT_H
#define PROJECT4_TWOSORT_H

#include <vector>
#include "mergeSort.h"
#include "insertionSort.h"
#include "Song.h"

void insertionSort2(vector<Song> vec, int &reads, int &writes) {
    int unsortedStartIndex, insertIndex;
    Song toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex]; // 1 read, 1 write
        ++reads;
        ++writes;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex].getPosition() > toBeInserted.getPosition()) { // 2 reads
            vec[insertIndex + 1] = vec[insertIndex]; // 1 read, 1 write
            reads += 3;
            ++writes;
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted; // 1 read, 1 write
        ++reads;
        ++writes;
//        printVec(vec);
    }
}
void twoSort(vector<Song> vec, int &reads, int &writes) {
    insertionSort(vec, reads, writes);
    insertionSort2(vec, reads, writes);
}
#endif //PROJECT4_TWOSORT_H
