#include "bubbleSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
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

    //Create output csv file
    ofstream sortingData;
    sortingData.open("../data/sortingData.csv");

    sortingData << "Algorithm,Reads,Writes" << endl;
    //Bubble Sort
    reads = 0;
    writes = 0;
    bubbleSort(songs, reads, writes);
    sortingData << "Bubble Sort," << reads << "," << writes << endl;

    //Selection Sort
    reads = 0;
    writes = 0;
    selectionSort(songs, reads, writes);
    sortingData << "Selection Sort," << reads << "," << writes << endl;

    //Merge Sort
    reads = 0;
    writes = 0;
    mergeSort(songs, reads, writes);
    sortingData << "Merge Sort," << reads << "," << writes << endl;

    //Heap Sort
    reads = 0;
    writes = 0;
    heapSort(songs, reads, writes);
    sortingData << "Heap Sort," << reads << "," << writes << endl;

    //Two Sort
    reads = 0;
    writes = 0;
    twoSort(songs, reads, writes);
    sortingData << "Two Sort," << reads << "," << writes << endl;

    sortingData.close();

    return 0;
}