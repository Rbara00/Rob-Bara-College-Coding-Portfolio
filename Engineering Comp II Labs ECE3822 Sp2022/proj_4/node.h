#ifndef NODE_H
#define NODE_H

#include<math.h>
#include<vector>
#include"song.h"
#include <iomanip> //for printing pretty

/*=================================================
    Header and Functions for Node class
==================================================*/
//node class definitions
class node{
    public:
    node(song*);                        //node contains pointer of songs
    node* get_left();                   //gets the left node
    node* get_right();                  //gets the right node
    void set_left(node*);               //sets the left node
    void set_right(node*);              //sets the right node
    void set_node_idx(int );            //sets the node index based on hashed song id 
    int get_node_idx();                 //returns the hased song node id
    void set_node_num(int);             //sets the n'th node number when it is created
    int get_node_num();                 //gets which number in the node count, this node is
    void add_band(song*);               //pushes a band into a vector that has played the specified song
    void print_song_info(int,string);   //prints the target song and band
    int get_max_traversals();

    private:
    vector<song*> stored_songs;         //vector of pointers to songs
    int node_idx;                       //hashed song id
    int node_num;                       //which n'th node this is upon creation
    node* left;                         //left child of current node
    node* right;                        //right child of current node
    int max_traversals=0;
    void display(int);                  //prints the song, artist, complexity, and position it is in the tree
};

// node constructor
node::node(song* curr_song){
    stored_songs.push_back(curr_song);  //vector of songs to keep track of each band that has played them
    node_idx=0;                         //initialize the hashed id to 0
    left = NULL;                        //initialize left child
    right = NULL;                       //initialize right child
}

// setters and getters
void node::set_left (node* ptr){left  = ptr;}
void node::set_right(node* ptr){right = ptr;}
void node::set_node_idx(int n){ node_idx=n;}
node* node::get_left() { return left;}
node* node::get_right(){ return right;}
int node::get_node_idx(){ return node_idx; }
void node::set_node_num(int node_count){node_num=node_count;}
int node::get_node_num(){return node_num;}
int node::get_max_traversals(){return max_traversals;}

//adds a band to the vector of the specified song
void node::add_band(song* next_song){
    stored_songs.push_back(next_song);
}

//prints the information stored within the node's vector
void node::display(int i){
    //how many traversals across the node and vector it took to find the song
    int traversals=node_num+i;
    if(traversals>max_traversals) max_traversals=traversals; //update the worst case scenario
    //print our the complexity and song/artist stored in node at vector[i]
    cout<<fixed<<"Complexity= Node + Index = N"<<node_num<<" + "<<i<<" = "<<traversals
        <<"\t\tlog2("<<traversals<<")="<<setprecision(6)<<log2(traversals)<<"\t\t"
        <<stored_songs[i]->get_band()<<" ->> "<<stored_songs[i]->get_song()<<endl;
}

//prints the node number at time of insertion, the stored song, and artist
void node::print_song_info(int idx,string target_band){
    //traverse the vector of bands that has played this song
    for(int i=0;i<stored_songs.size();i++){
        //when the band we are looking for is found,
        if(stored_songs[i]->get_band()==target_band){
            display(i);     //print information to terminal
        }
    }
}

#endif