#include<iostream>
#include<cmath>
#include "heap.h"
using namespace std;

int binary_heap::left(int i)  {return 2*i + 1;}
int binary_heap::right(int i) {return 2*i + 2;}
int binary_heap::parent(int i){return floor( (i-1)/2 ); }

void binary_heap::swap(int a , int b){
    int tmp = buffer[a];
    buffer[a] = buffer[b];
    buffer[b] = tmp;
    
    swapCnt++;
}

void binary_heap::bubble_up(int n){
    if (n==0)
        return;
    else{
        if (buffer[n] > buffer[parent(n)]){
            swap(n , parent(n));
            bubble_up(parent(n));
        }
        else
            return;
    }
}

bool binary_heap::is_valid_index(int i){
    return (i<n_items);
}

bool binary_heap::has_children(int i){
    if ( is_valid_index( left(i) ) )
        return true;
    else
        return false;
}

int binary_heap::get_largest_child(int i){
    // guaranteed that left child exists
    // not guaranteed that right child exists
    int i_child = left(i);

    if ( is_valid_index( right(i) ) )
        if (buffer[right(i)] > buffer[left(i)])
        i_child = right(i);

    return i_child;
}

void binary_heap::bubble_down(int i_curr_node=0){
    
    // is current node greater than both children?
    // if yes, stop
    // if no, swap w/ greater child and repeat

    int curr_value = buffer[i_curr_node];

    if (!has_children(i_curr_node) )
        return;
    int i_largest_child = get_largest_child(i_curr_node);

    if (buffer[i_curr_node] < buffer[i_largest_child]){
        swap(i_curr_node , i_largest_child);
        bubble_down(i_largest_child);
    }

}

binary_heap::binary_heap(){
    buffer = NULL;
}

void binary_heap::insert(int data){
    buffer[n_items] = data;
    bubble_up(n_items);
    n_items++;
}    

void binary_heap::print_buffer(){
    for (int i = 0 ; i<buffsize ; i++)
        cout << buffer[i] << endl;
    cout <<"\n" << endl;
}

int binary_heap::pop(){
    int return_val = buffer[0];
    
    swap(0 , n_items-1);
    n_items--;
    bubble_down();
    
    return return_val;
}

int binary_heap::sort(){
    int n = n_items;
    int val;
    for (int i = 0 ; i<n; i++){
        val = pop();
        buffer[n_items] = val;
    }
    
    return swapCnt;
}

void binary_heap::reset(int _buffsize){
    buffsize = _buffsize;
    delete [] buffer;
    buffer = new int[buffsize];
    n_items = 0;
    swapCnt = 0;
}