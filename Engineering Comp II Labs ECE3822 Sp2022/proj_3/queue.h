#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<vector>
#include"student.h"
using namespace std;
class queue{
    private:
    vector<student*> studentQueue;       //vector of type students, this is the queue
    int queueSize;                      //current size of the queue
    
    public:
    queue();                  //constructor creates the queue and clears the vector
    void push_back(student*);  //push a student to the back of the queue
    student* pop_back();       //pops a student from the back of the queue
    void clear_all();         //clears the queue and resets the queue size
    student* front();         //returns the student at the front of the queue
    student* back();          //returns the student at the back of the queue
    bool empty();             //checks if the queue is empty or has data 
    int get_len();            //returns the amount of data stored in the queue
};

#endif