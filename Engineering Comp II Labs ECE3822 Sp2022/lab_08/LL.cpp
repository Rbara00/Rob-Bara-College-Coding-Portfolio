#include "LL.h"
#include<iostream>

//linked list class
//constructor for linked list
LL::LL(){
    head=NULL;  //set the head to null to initialize
    
}

//adds a node to the list
void LL::push(int d){
    LL_Node *data = new LL_Node(d,head);
    head = data;
}

//prints all nodes within the list
void LL::printAll(){
    LL_Node *curr = head;
    while (curr!=NULL){
        if (curr->next == NULL)
            curr->print_last();
        else
            curr -> print();
        curr = curr->next;
    }
    if (head==NULL)
        std::cout << std::endl;
}