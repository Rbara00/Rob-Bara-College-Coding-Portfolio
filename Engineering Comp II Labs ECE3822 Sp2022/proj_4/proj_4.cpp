#include"hash_table.h"
#include"bst.h"
#include<chrono>

using namespace std::chrono;
using namespace std;
/*proj_4.cpp
   Robert Bara
   tuj22026@temple.edu
   03/29/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
    This program utilzies two different methods of reading data from a file and sorting them into a database. The two
    methods are a binary search tree and hash table. Both algorithms are implemented through their respective classes
    and sort/store from a file of 7000 unique bands with their respective songs. This driver program opens the file,
    stores the data to both the BST and Hash Table, then it reopens the file and records how long/the complexity it
    takes to find that specific song/artist.

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make all
    Run:    ./proj_4 <arg>  , where arg can be 0, 1
                              0->sorts the data using a binary search tree
                              1->sorts the data using a hash table
*/

/*=================================================
    Driver Program
==================================================*/
bst songBST;
hash_table songTable;

//loads songs by artists from a file, into a binary search tree of vectors and a hash table of vectors
void load_function(){    
    string filename_complete = "/data/courses/ece_3822/current/proj_4/songlist.txt";
    //string filename_complete = "/home/tuj22026/labs/proj_4/songs.txt"; //test it on a smaller file

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()); // erase the carriage return at the end

        //create a hashed index for the song
        int idx=songTable.hash_function(song_title);
        //create a pointer to a new song
        song* curr_song=new song(song_title, band_name, idx);

        //insert into the binary search tree
        songBST.insert(curr_song);
        //insert into the hash table
        songTable.insert(curr_song);
    }
    f_id.close();

}

//reads from the bst
void analyze_function_bst(){
    string filename_complete = "/data/courses/ece_3822/current/proj_4/songlist.txt";
    //string filename_complete = "/home/tuj22026/labs/proj_4/songs.txt"; //test it on a smaller file

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string band_name;
    string line;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()); // erase the carriage return at the end

        /*  so while this is an implementation of a binary search tree, I figured that
            it would make my life a lot easier if I assigned each node a key which is an
            integer, this way I can sort/traverse through them very easily. A couple options
            I could've done were to sum the ascii values of the band name or song name and create
            a node specific to each song, either way the value at the nodes are going to be unique
            so I figured my key could just be a hashed index based from the song name, and for 
            consistency, I just copied the hash function over from the hashtable into the binary
            search tree class, this way it will be consistent an work independently from the table class.
        */
        int idx=songBST.hash_function(song_title);
       
        //search through bst
        node* root=songBST.get_root();
        songBST.print_node(idx,root,band_name);
       
    }
    cout<<"\nThe number of nodes in BST: "<<songBST.get_node_count()<<endl;
    cout<<"The worst case scenario-> Max Traversals: "<<songBST.get_max_traversals()<<
        "\nAverage traversals: log2("<<songBST.get_node_count()<<")="<<log2(songBST.get_node_count())<<endl;

    cout<<"\nRun again for hash table analysis to compare efficiency"<<endl;
    f_id.close();
}

//reads from the hash table
void analyze_function_table(){
    string filename_complete = "/data/courses/ece_3822/current/proj_4/songlist.txt";
    //string filename_complete = "/home/tuj22026/labs/proj_4/songs.txt"; //test it on a smaller file

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string band_name;
    string line;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()); // erase the carriage return at the end

        //search through the table for all songs
        songTable.print_song(song_title,band_name);
    }
    cout<<"\nTable Size: "<<songTable.size()<<"\t\t"
        <<"The number of slots filled in the Table: "<<songTable.get_table_slots_filled()<<endl;
   
    cout<<"The maximum hash ID: "<<songTable.get_max_hashId()<<endl;
    cout<<"The max traversals: "<<songTable.get_max_traversals()<<endl;


    cout<<"\nAs we can see, based upon max traversals and number of slots filled within the table,\n"
        <<"a hash table uses more memory in terms of table columns than the amount of the binary search tree's nodes.\n"
        <<"however when searching, the hash table uses less traversals than a binary search tree, therefore it is less complex"<<endl;

    f_id.close();
}

int main(int argc, char** argv){
    cout<<"\n-----------------Loading Songs-----------------"<<endl;
    load_function();

    if (argc !=2 ){
        cout << "ERROR: include a command line arguement of 0 or 1 " << endl;
        return -1;
    }

    //determines which analysis to run
    switch (stoi(argv[1])){
        case 0:{
                cout<<"\n-----------------Analyzing BST-----------------"<<endl;
                analyze_function_bst();
                break;
            }
        case 1:{
                cout<<"\n-----------------Analyzing Table-----------------"<<endl;
                analyze_function_table();
                break;
            }
    }
    

    return 0;
}
