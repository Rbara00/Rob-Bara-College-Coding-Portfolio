#include "Tree_Node.h"
#include<iostream>
using namespace std;

//Tree Node Class
//constructor for the tree node
Tree_Node::Tree_Node(int k, Tree_Node *l, Tree_Node *r){
    key = k;
    left = l;
    right = r;
    treeList = new LL;
}

//function prints an individual node that is specified
void Tree_Node::print(){
    cout << key << ": ";
    treeList->printAll();
}

//function prints all nodes within the tree, with no given order
void Tree_Node::printTree(){
    print();                //call print function current node
    if(left!=NULL){         //check if left node exists
        left->printTree();  //recurse to print and keep checking the next left node
        left=left->left;    //update to the next left node
    }
    if(right!=NULL){        //check if right node exists
        right->printTree(); //recuse to print and keep checking the right node
        right=right->right; //update to the next right node
    }
}