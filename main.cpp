#include "bubbleSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "twoSort.h"
#include "Song.h"
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
    //make csv header line
    sortingData << "Vector Size,Algorithm,Reads,Writes,Duration" << endl;
    int vecSize;

    for(int i = 0; i < 11; ++i) {
        vecSize = 100*i;
        songs.resize(vecSize);
        //Bubble Sort
        reads = 0;
        writes = 0;
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(songs, reads, writes);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
        sortingData << vecSize << ",Bubble Sort," << reads << "," << writes << "," << duration.count() << endl;


        //Selection Sort
        reads = 0;
        writes = 0;
        start = std::chrono::high_resolution_clock::now();
        selectionSort(songs, reads, writes);
        stop = std::chrono::high_resolution_clock::now();
        duration = duration_cast<std::chrono::milliseconds>(stop - start);
        sortingData << vecSize << ",Selection Sort," << reads << "," << writes << "," << duration.count() << endl;

        //Merge Sort
        reads = 0;
        writes = 0;
        start = std::chrono::high_resolution_clock::now();
        mergeSort(songs, reads, writes);
        stop = std::chrono::high_resolution_clock::now();
        duration = duration_cast<std::chrono::milliseconds>(stop - start);
        sortingData << vecSize << ",Merge Sort," << reads << "," << writes << "," << duration.count() << endl;

        //Heap Sort
        reads = 0;
        writes = 0;
        start = std::chrono::high_resolution_clock::now();
        heapSort(songs, reads, writes);
        stop = std::chrono::high_resolution_clock::now();
        duration = duration_cast<std::chrono::milliseconds>(stop - start);
        sortingData << vecSize << ",Heap Sort," << reads << "," << writes << "," << duration.count() << endl;

        //Two Sort
        reads = 0;
        writes = 0;
        start = std::chrono::high_resolution_clock::now();
        twoSort(songs, reads, writes);
        stop = std::chrono::high_resolution_clock::now();
        duration = duration_cast<std::chrono::milliseconds>(stop - start);
        sortingData << vecSize << ",Two Sort," << reads << "," << writes << "," << duration.count() << endl;
    };

    sortingData.close();

    return 0;
}