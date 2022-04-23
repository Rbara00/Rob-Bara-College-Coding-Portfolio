#ifndef  LL_NODE_H 
#define LL_NODE_H 

//linked list node class header
class LL_Node{
    public:
    int data;   //data the linked list node holds
    LL_Node *next; //pointer to the next node in the linked list
    LL_Node(int, LL_Node*); //constructor for a node, takes in data and the pointer to the next node
    void print();           //prints the node's data
    void print_last();      //prints the last node
};

#endif