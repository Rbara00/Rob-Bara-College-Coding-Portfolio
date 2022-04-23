#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include <fstream>
#include"song.h"
using namespace std;

/*=======================================
    Header and Functions for Song Class
  =======================================*/
class song{
    private:
        string song_title;  //name of song
        string band_name;   //name of artist
        int index;          //hashed index

    public:
        //constructor for a song, holds the artist, track name, and hashed id
        song(string curr_song, string artist, int idx){
        song_title= curr_song;
        index=idx;
        band_name = artist;
        }
        //setter for index
        void set_index(int i){ index=i;}
        //getter for the song name
        string get_song(){ return song_title;}
        //getter for the band's name
        string get_band(){ return band_name;}
        //getter for hashed index
        int get_index(){return index;}

};

#endif