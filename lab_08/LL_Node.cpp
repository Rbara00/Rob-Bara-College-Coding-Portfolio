#include "LL_Node.h"
#include <iostream>
using namespace std;
//linked list node class
// constructor for linked list node
LL_Node::LL_Node(int d, LL_Node* n){
        data = d;
        next = n;
    
}
//prints the data of the node
void LL_Node::print(){
        cout << data << " -> ";
}
//for printing the last node
void LL_Node::print_last(){
        cout << data << endl;
}
