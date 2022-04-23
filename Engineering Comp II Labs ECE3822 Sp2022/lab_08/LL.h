#include "LL_Node.h"

#ifndef  LL_H 
#define LL_H 

//linked list class header
class LL{
    public:
    LL_Node *head;  //pointer to the head node of the list
    LL();           //constructor for the linked list
    void push(int); //pushes a new node to the list
    void printAll();//prints all the nodes within the list
};

#endif