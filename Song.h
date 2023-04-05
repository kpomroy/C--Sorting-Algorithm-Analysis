//
// Created by Kevin Pomroy on 1/25/23.
//

#ifndef SONG_SONG_H
#define SONG_SONG_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
//use specific std objects in h (class) files
using namespace std;
//using std::cout, std::endl, std::ifstream, std::string, std::vector, std::ostream;

class Song {
private:
    int position;
    string artist;
    string title;
    int days;
    int streams;

public:
    //Constructors
    Song() {
    }

    Song(int position, string artist, string title, int days, int streams) {
        this->position = position;
        this->artist = artist;
        this->title = title;
        this->days = days;
        this->streams = streams;
    }

    //Getters
    int getPosition() const {
        return position;
    }

    string getArtist() const {
        return artist;
    }

    string getTitle() const {
        return title;
    }

    int getDays() const {
        return days;
    }

    int getStreams() const {
        return streams;
    }

    // Setters
    void setPosition(int position) {
        this->position = position;
    }

    void setArtist(string artist) {
        this->artist = artist;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setDays(int days) {
        this->days = days;
    }

    void setStreams(int streams) {
        this->streams = streams;
    }

    //Overloaded Operators
    friend ostream& operator << (ostream& os, const Song& s) {
        os << s.getTitle() << " by " << s.getArtist() << " days since release: " << s.getDays();
        return os;

    }

    friend bool operator <(const Song& s1, const Song& s2) {
        return (s1.getDays() < s2.getDays());
    }

    friend bool operator <=(const Song& s1, const Song& s2) {
        return (s1.getDays() < s2.getDays() || s1.getDays() == s2.getDays());
    }

    friend bool operator >(const Song& s1, const Song& s2) {
        return (s1.getDays() > s2.getDays());
    }

    friend bool operator >=(const Song& s1, const Song& s2) {
        return (s1.getDays() > s2.getDays() || s1.getDays() == s2.getDays());
    }

    friend bool operator ==(const Song& s1, const Song& s2) {
        return (s1.getDays() == s2.getDays());
    }

    friend bool operator !=(const Song& s1, const Song& s2) {
        return (s1.getDays() != s2.getDays());
    }

};

void getDataFromFile(string filename, vector<Song>& songs) {

    //create a file handler object
    ifstream inFile;
    //open the file
    inFile.open(filename);

    string header;

    //check if the file can be read from
    if (inFile) {
        //read a full line from the inFile into the header string
        getline(inFile, header);
    }

    // Declare variables to be read in from csv
    string artist = "", title = "", junk, peakPositionTimes;
    int position = -1, days = -1, streams = -1, peakPosition, peakStreams;
    double top10;
    char comma, quote;

    //While the file is still in a good state to be read from
    //and we're not at the end of the file (check for end of file character)
    //inFile.peek() looks at next character
    while (inFile && inFile.peek() != EOF) {
        // Position
        inFile >> position >> comma;

        // Artist
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile, artist, '"');
            inFile >> comma;
        } else {
            getline(inFile, artist, ',');
        }

        // remove blank space after artist names
        // erase() fuction found on stackoverflow
        artist.erase(artist.end() - 1);

        // Title
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile, title, '"');
            inFile >> comma;
        } else {
            getline(inFile, title, ',');
        }

        // Days since release
        inFile >> days >> comma;

        // Top 10 (ignore column)
        inFile >> top10 >> comma;

        // Peak Position (ignore column)
        inFile >> peakPosition >> comma;

        // Peak Position (xTimes) (ignore column)
        getline(inFile, peakPositionTimes, ',');

        // Peak Streams (ignore column)
        inFile >> peakStreams >> comma;

        // Streams
        inFile >> streams;

        //Create a song object and add it to the vector
        songs.push_back(Song(position, artist, title, days, streams));
    }

    //close the file
    inFile.close();
};

int artistNumSongs(vector<Song> songs, string artist) {
    int count = 0;
    for(int i = 0; i<songs.size(); i++) {
        string testArtist = songs[i].getArtist();
        if (artist == testArtist) {
            count++;
        }
    }
    return count;
};



#endif //SONG_SONG_H