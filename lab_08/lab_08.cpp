#include<iostream>
#include "LL.h"
#include "Tree_Node.h"
using namespace std;
/*lab_08.cpp

   Robert Bara
   tuj22026@temple.edu
   03/15/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This program is an implementation of a Binary Tree. This program in particular is a driver for the class files
   and adds 6 nodes to the binary tree. Finally, it prints all the nodes within the tree in no particular order.

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make all
    Run:    ./lab_08.exe
*/
int main(){
    //declare tree nodes
    Tree_Node n0(0,NULL,NULL);
    Tree_Node n1(1,NULL,NULL);
    Tree_Node n2(2,NULL,NULL);
    Tree_Node n3(3,NULL,NULL);
    Tree_Node n4(4,NULL,NULL);
    Tree_Node n5(5,NULL,NULL);
    Tree_Node n6(6,NULL,NULL);

    //declare pointers to left and right for tree
    n0.left  = &n1;
    n0.right = &n2;
    n1.left  = &n3;
    n1.right = &n4;
    n2.left  = &n5;
    n2.right = &n6;
    
    //add nodes with data to the tree
    n0.treeList -> push(85);
    n0.treeList -> push(92);
    n0.treeList -> push(97);
    n1.treeList -> push(65);
    n1.treeList -> push(61);
    n3.treeList -> push(55);
    n4.treeList -> push(66);
    n4.treeList -> push(27);
    n5.treeList -> push(87);
    n5.treeList -> push(67);
    n5.treeList -> push(39);
    n6.treeList -> push(76);


    ////////////////////////////////////////////////
    /* Printing all the nodes within the tree
    ----------------------------------------------*/
    n0.printTree();

    return 0;
}