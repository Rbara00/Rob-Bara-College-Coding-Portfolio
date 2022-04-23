#include<iostream>
#include"queue.h"
using namespace std;

//----------------------------------------------------------------------------------
//QUEUE CLASS
//----------------------------------------------------------------------------------
//constructor for queue, creates a cleared vector for storing students
queue::queue(){
    studentQueue.clear(); //clearing the vector
    queueSize=0;          //initialize the current size of the queue
}

//pushes a new student to the back of the queue
void queue::push_back(student* new_student){
    studentQueue.push_back(new_student);    //insert student onto the back of the vector
    queueSize++;                            //increase queue size by 1
}

//pops a student from the back of the queue
student* queue::pop_back(){
    student* popped_student=studentQueue.back();
    studentQueue.pop_back();                //remove student from the back of the vector
    queueSize--;                            //decrease queue size by 1
    return popped_student;                  //return the student in the back of the vector
}

//gets the student at the front of the queue
student* queue::front(){
    return studentQueue.front(); //dereference front
}

//gets the student at the back of the queue
student* queue::back(){
    return studentQueue.back(); //dereference back
}

//clears the queue
void queue::clear_all(){
    studentQueue.clear();   //clears all elements within the vector
    queueSize=0;            //initialize the current size to 0
}

//getter for the queue size
int queue::get_len(){
    return queueSize;       //return the queue size
}

//checks if the queue is empty
bool queue::empty(){
    bool return_val=false;
    if(queueSize==0) return_val=true; //when queue size is 0 there is nothing in the queue
    return return_val;
}