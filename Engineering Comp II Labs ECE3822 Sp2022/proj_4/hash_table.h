#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<vector>
#include"song.h"

using namespace std;

/*=========================================================
    Header and Functions HashTable Class
===========================================================*/
class hash_table{
    private:
    vector<song*> *table;                   // table is an array of vectors of pointers-to-songs
    int array_len;                          //size of the table
    bool search_song(int,string,bool);      //searches if there correct song is at hashed id location
    int max_hash_id=0;
    int max_traversals=0;
    int table_slots_filled=0;

    public:
    hash_table(int);                        //constructor for the hash table
    int hash_function(string);              //hashes a song based upon the song's title
    void insert( song* );                   //inserts a pointer to a song into the table
    void print_song(string,string);            //prints song at the specified hash id, if valid
    void display(int, int, int);            //prints the information of the song to the terminal
    int get_max_hashId();                   //getter for the largest hash index value
    int get_max_traversals();               //gets the maximum number of traversals
    int get_table_slots_filled();           //getter to see how many columns have been filled
    int size();                             //getter for the size of the table, returns array_length
};

//constructor for hash table with dynamic memory allocation
hash_table::hash_table(int n=1000){    
    // dynamic memory allocation for the table
    // array length is a user-defined variable
     //array length is defaulted to 1000 which is enough for 7000 enteries since we are using vectors for collisions
    array_len = n;
    table = new vector<song*>[array_len];
}
//getters for complexity:largest hash id and number of songs
int hash_table::get_max_hashId(){ return max_hash_id;}
int hash_table::get_max_traversals(){ return max_traversals;}
int hash_table::get_table_slots_filled(){ 
    for(int i=0;i<array_len;i++){
        if(table[i].empty()==true) table_slots_filled++;
    }
        return table_slots_filled;

    }
int hash_table::size(){return array_len;}
//hash function takes in the song's name, adds the ascii, and mods it with size of table
int hash_table::hash_function(string song_title){
    int s = 0;
    for (int i = 0; i<song_title.length(); i++){
        /*
            Using Ascii values, square the next character by the current character
            and multiply this by the current character, then add that the integer s
            and move on to the next two characters until the song title is completely 
            iterated through
        */
        s += (int)((song_title[i+1])^song_title[i])*(int)(song_title[i]);
    }
    return s % array_len;      //generating key based on song's title modded with array len
}

//inserts a pointer to the next song into a vector at the hashed index
void hash_table::insert(song* next_song){
    int index=next_song->get_index();         // get song's hashed index
    table[index].push_back( next_song );      // insert next song into vector at hashed index
    if(index>max_hash_id) max_hash_id=index;  // keep track of the largest known filled index
}

//Prints the song if it is found witihn the table based on hashed id
void hash_table::print_song(string target_song_name, string target_band_name){
    int target_songId=hash_function(target_song_name);    //get the target hashed id
    search_song(target_songId , target_band_name, true); //search the song, print if found, otherwise print not found
}

//Searches if the table contains the song at specified hashed index. Optionally can print information and complexity
bool hash_table::search_song(int target_songId,string target_band_name, bool printFlag){
    bool return_val = false;
    //for counting how complicated the table search is
    int rowCount=0;
    
    // this tells me which vector to search
    int index=target_songId;
    // now I have to search the vector table[index] to see if it contains target
    for (int i = 0; i < table[index].size() ; i++){
        rowCount++;//increase column count
        //check if it is the correct band
        string band_name=table[index][i]->get_band();
        if (band_name == target_band_name){
                // target is found
                return_val = true;
                //print information if print flag is high
                if(printFlag==true) {
                    display(rowCount,index,i);
                }
        }
    }
    if (return_val==false) cout<<"Not found"<<endl;

    return return_val;
}

//prints the complexity and song information to the terminal
void hash_table::display(int rowCount, int index, int i){
    int traversals=1+rowCount;
    if(traversals>max_traversals) max_traversals=traversals;
    cout<<"Complexity = HashIdx("<<index<<") + Index = "<<1<<" + "<<rowCount<<" = "<<traversals
        <<"\t"<<table[index][i]->get_band()<<" ->> "<<table[index][i]->get_song()<<endl;
}


#endif