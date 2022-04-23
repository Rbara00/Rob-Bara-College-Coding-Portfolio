#include "bubble.h"
#include<iostream>
using namespace std;

bubble_sort::bubble_sort(){
    buffer = NULL;
}

void bubble_sort::reset(int _buffsize){
    buffsize = _buffsize;
    swap_count = 0;
    i_curr = 0;
    if (buffer != NULL)
        delete [] buffer;
    buffer = new int[buffsize];
}

void bubble_sort::insert(int val){
    if (i_curr<buffsize)
        buffer[i_curr++] = val;
}

void bubble_sort::swap(int i, int j){
    int tmp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = tmp;
    swap_count++;
}

int bubble_sort::sort(){
    int i,j;

    for (i=0;i<buffsize;i++){

        for (j=buffsize-i-1 ; j>0 ; j--){

            if (buffer[j] < buffer[j-1])
                swap(j,j-1);

        }

    }

    return swap_count;
}

void bubble_sort::print(){
    for (int i = 0;i<buffsize-1; i++)
        cout << buffer[i] << " --> ";
    cout << buffer[buffsize-1] << endl;
}