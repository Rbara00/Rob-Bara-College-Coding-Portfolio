#include "circularBuffer.h"
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

circularBuffer::circularBuffer(int size){
    buff_size=size;         //the size of the buffer determined by the value passed in
    buff=new int[size];     //initializing the buffer to be an array of ints
    average=0;              //initializing average
    indx=0;                 //initializing the counter for the average calculation
    indx_3=0;               //initializing counter + 3 for average calculation
    i=0;                    //iterator for moving elements when inserting buffer
    j=0;                    //iterator for moving elements when inserting buffer
    for(int i=0;i<=size-1;i++) buff[i]=0;  //initializing the buffer with 0's
}

void circularBuffer::insert(int addpoint){
   /*
    The for loop allows for the previous inserted element to move up to the next index. 
    When the buffer is full that it, inserts one element only to the '0' element, overwriting the oldest element
    more or less acting as follows, for example this is for a buffer with buff size = 4
    buff[3]=buff[2];
    buff[2]=buff[1];
    buff[1]=buff[0];    
    buff[0]=addpoint;
*/
    i=buff_size-1; //iterator to move element to next index
   for(int i=buff_size-1;i>=1;i--){
        j=i-1;         //current iterator
        buff[i]=buff[j]; //set next element to previous element, stop when exceeds the buffer size
    }
     buff[0]=addpoint; //add a point to the '0' position
}

float circularBuffer::getAverage(int point){
    /*indx is used for the first position. It takes the value passed in and 
      converts it to the corresponding range within the circular buffer.
      indx_3 is for indx+3, which is the position of the second point used
      to calculate the average
    */
    indx=point%buff_size;
    indx_3=(point+3)%buff_size;

    /*for debugging only
    cout<<"Items in Buffer:"<<endl;
    for(int i=0;i<=buff_size-1;i++) cout<<buff[i]<<" ";
    cout<<endl<<"Passed in indx: "<<point<<" | indx (mod): "<<indx<<" | buff[indx]: "<<buff[indx]<<" | next indx: "<<point+3<<" | next indx(mod): "<<indx_3<<" | buff[next indx] "<<buff[indx_3]<<endl<<endl;
    */

    //compute the average
    average=(buff[indx]+buff[indx_3])/2.0;//average is computed as sum of two points divided by total number of points
    return average; //return the average
}
