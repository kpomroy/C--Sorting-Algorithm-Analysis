#ifndef PROJECT4_TWOSORT_H
#define PROJECT4_TWOSORT_H

#include <vector>
#include "mergeSort.h"
#include "insertionSort.h"
#include "Song.h"

void insertionSort2(vector<Song> vec) {
    int unsortedStartIndex, insertIndex;
    Song toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex].getPosition() > toBeInserted.getPosition()) {
            vec[insertIndex + 1] = vec[insertIndex];
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
        printVec(vec);
    }
}
void twoSort(vector<Song> vec) {
    insertionSort(vec);
    insertionSort2(vec);
}
#endif //PROJECT4_TWOSORT_H
