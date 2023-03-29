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

    // Get data from csv of top 1000 streamed songs on Spotify
    getDataFromFile("../spotify_songs.csv", songs);

    //Bubble Sort
    bubbleSort(songs);

    //Selection Sort
    selectionSort(songs);

    //Merge Sort
    mergeSort(songs);

    //Heap Sort
    heapSort(songs);

    //Two Sort
    twoSort(songs);

    return 0;
}