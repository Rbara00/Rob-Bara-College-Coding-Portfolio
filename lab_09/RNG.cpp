#include "RNG.h"
#include<iostream>
#include<cstdlib>

//***************************************************************
//********** constructor
//***************************************************************
RNG::RNG(int ms = 1000000){
    maxsize = ms;
    buffer = new bool[maxsize];
    reset();
    srand (time(NULL));
}

//***************************************************************
//********** reset status
//***************************************************************
void RNG::reset(){
    for (int i=0;i<maxsize;i++)
        buffer[i] = false;
}

//***************************************************************
//********** generate random int without repeats
//***************************************************************
int RNG::gen(){
    int val;
    while(true){
        val = rand() % maxsize;
        if (buffer[val] == false){
            buffer[val] = true;
            break;
        }
    }
    return val;
}
