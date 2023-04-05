#include "bubbleSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "insertionSort.h"
#include "twoSort.h"
#include "Song.h"
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<Song> songs;
    int reads;
    int writes;

    // Get data from csv of top 1000 streamed songs on Spotify
    getDataFromFile("../spotify_songs.csv", songs);

    //Bubble Sort
    reads = 0;
    writes = 0;
    bubbleSort(songs, reads, writes);
    cout << "Bubble Sort: reads: " << reads << " writes: " << writes;

    //Selection Sort
    reads = 0;
    writes = 0;
    selectionSort(songs, reads, writes);
    cout << "Selection Sort: reads: " << reads << " writes: " << writes;

    //Merge Sort
    reads = 0;
    writes = 0;
    mergeSort(songs, reads, writes);
    cout << "Merge Sort: reads: " << reads << " writes: " << writes;

    //Heap Sort
    reads = 0;
    writes = 0;
    heapSort(songs, reads, writes);
    cout << "Heap Sort: reads: " << reads << " writes: " << writes;

    //Two Sort
    reads = 0;
    writes = 0;
    twoSort(songs, reads, writes);
    cout << "Two Sort: reads: " << reads << " writes: " << writes;

    return 0;
}