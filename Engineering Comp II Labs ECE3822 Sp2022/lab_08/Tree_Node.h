#include "LL.h"

#ifndef  TREE_NODE_H 
#define TREE_NODE_H 

//Tree Node Class Header
class Tree_Node{
    public:
    int key;    //key for the tree
    LL *treeList; //pointer of type linked list, points to the tree
    Tree_Node *left;    //pointer to the left node
    Tree_Node *right;   //pointer to the right node
    Tree_Node(int, Tree_Node*, Tree_Node*); //constructor for the tree node
    void print();       //prints the current node called upon
    void printTree();   //prints all nodes within the tree, no order
};

#endif