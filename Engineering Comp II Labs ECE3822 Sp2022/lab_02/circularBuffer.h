#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

class circularBuffer{

    public:
    // Don't alter these three function declarations
    circularBuffer(int);    //constructor for a circular buffer
    void insert(int);       //insert an element into the 0 position and move elements up
    float getAverage(int);  //compute the average of a passed in point, and the point 3 points up

    // feel free to add private and public functions/variables to this class
    // as needed

    private:
    int* buff; //pointer to the circular buffer
    int buff_size; //size of the circular buffer
    int indx;      //first position for average calculation 
    int indx_3;    //first position + 3 for average calculation
    int i;         //pushes the previous element to the next
    int j;         //the current index
    float average;
};

#endif
