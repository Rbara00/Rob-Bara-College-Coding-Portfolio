#ifndef BST_H
#define BST_H

#include"node.h"
/*=================================================
    Header and Functions for BST class
==================================================*/
//Binary Search Tree Function Definitions
class bst{

    public:
    bst();                              //constructor for BST
    void insert(song*);                 //insert a song into a node
    int hash_function(string);          //generates a key for the node based upon the song title
    int  get_node_count();              //returns how many nodes are in the tree
    void print_node(int,node*,string);  //prints song by specified band within specific node
    node* get_root();                   //returns the root of the ree
    int get_max_traversals();           //returns the max number of traversals within the tree and node

    private:
    node* root;
    int max_traversals=0;               
    int count_node=0;                   //counter for how many nodes
};

//constructor for the binary search tree
bst::bst(){
    root = NULL;
}

//getter for the root of the tree
node* bst::get_root(){ return root;}
//returns the current number of nodes within the BST
int bst::get_node_count(){ return count_node;}
//returns the maximum number of traversals to find and print the correct song within a node
int bst::get_max_traversals(){return max_traversals;}

//generates a unique key to be assigned to each node for traversal based upon the song name
int bst::hash_function(string song_title){
    int s = 0;
    /*
        Using Ascii values, square the next character by the current character
        and multiply this by the current character, then add that the integer s
        and move on to the next two characters until the song title is completely 
        iterated through
    */
    for (int i = 0; i<song_title.length(); i++){
        s += (int)((song_title[i+1])^song_title[i])*(int)(song_title[i]);
    }
    return s % 1000;      //generating key based on song name modded with a large enough size for 7000 enteries
}

//inserts a node specific to a song and band, into the binary tree
void bst::insert(song* new_song){

    // step 0: special case -> empty tree
    if (root == NULL){
        node* new_node_ptr = new node(new_song);            //create node for song
        count_node++;                                       //increase how many nodes there are
        new_node_ptr->set_node_num(count_node);             //set when this node was created
        new_node_ptr->set_node_idx(new_song->get_index());  //set the node's hashed index
        root=new_node_ptr;                                  //set root to be first song
        return;
    }

    //traverse BST
    node* parent = root;
    while (true){
            //step 1: check if the parent node shares the same song
            if(new_song->get_index()==parent->get_node_idx()){
                parent->add_band(new_song); //add band to vector
                break;
            }

            // step 2: Otherwise does new song go to the left?
            if ( new_song->get_index() < parent->get_node_idx() ){
                // does left node exists? if no, attach new song to left
                if ( parent->get_left() == NULL ){
                // step 3: create new node
                    node* new_node_ptr = new node(new_song);
                    count_node+=1;                                      //increase the node counter
                    new_node_ptr->set_node_num(count_node);             //set when this node was created
                    new_node_ptr->set_node_idx(new_song->get_index());  //set the node's hashed index
                    parent->set_left(new_node_ptr);
                    break;
                }
                // else branch to the left and repeat
                else{
                    parent = parent->get_left();
                }
            }

            // step2B: does new song go to the right?
            else{
                // if right branch doesn't exist, place new_node to the the right
                if ( parent ->get_right() == NULL){
                    // step 3: create new node
                    node* new_node_ptr = new node(new_song);
                    count_node+=1;                                      //increase the node counter
                    new_node_ptr->set_node_num(count_node);             //set when this node was created
                    new_node_ptr->set_node_idx(new_song->get_index());  //set the node's hashed index
                    parent->set_right(new_node_ptr);
                    break;
                }
                else{
                    parent = parent->get_right();
                }
            }
        }
}

//prints the specified song by band, by traversing through the tree
void bst::print_node(int idx,node* curr_node, string band_name){
    if (curr_node == NULL)
        return;
    // check if current node is the correct song
    if(curr_node->get_node_idx()==idx)
        curr_node->print_song_info(idx,band_name);
        if(curr_node->get_max_traversals()>max_traversals) max_traversals=curr_node->get_max_traversals();
    else {
        // Traverse all nodes with index smaller than me
        print_node(idx,curr_node->get_left(),band_name );

        // Traverse all nodes with index bigger than me
        print_node(idx,curr_node->get_right(),band_name );
    }
}

#endif