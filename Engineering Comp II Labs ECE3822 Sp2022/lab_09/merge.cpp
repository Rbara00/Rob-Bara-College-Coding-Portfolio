#include<iostream>
#include<iomanip>
#include "merge.h"

using namespace std;

merge::merge(){
    reset();
}

void merge::reset(){
    buffer.clear();
    copy_count = 0;
}

void merge::insert(int v){
    buffer.push_back(v);
}

int merge::sort(int ind_A, int ind_D){

    // 8 6 7 5 3 0 9 1
    // A     B C     D <-- indexes

    // ugly work around
    if (ind_D==-1)
        ind_D = buffer.size() - 1;
        
    int nElementsToBeSorted = (ind_D - ind_A + 1);
    int ind_B, ind_C, midpoint_offset;
    
    // divide buffer into left and right
    if (nElementsToBeSorted == 1)
        // recursion is complete
        return 0;
        // return;
    else{
        // select the mid point between left and right
        midpoint_offset = (nElementsToBeSorted / 2); // if list was 0-3, midpoint is 2
        ind_B = ind_A + midpoint_offset - 1;
        ind_C = ind_B + 1;
        
        sort( ind_A , ind_B ); // sort left subarray
        sort( ind_C , ind_D ); // sort right subarray
    }

    // merge the sublists
    merge_sublists( ind_A , ind_B , ind_C , ind_D );

    return copy_count;   
}

void merge::merge_sublists(int ind_A,int ind_B,int ind_C, int ind_D){
    int tmpVal;
    
    // create left and right sublists
    vector<int> sublist_left  ( &buffer[ind_A] , &buffer[ind_B]+1 );
    vector<int> sublist_right ( &buffer[ind_C] , &buffer[ind_D]+1 );
    
    // define the merged sublist (starts out empty)
    vector<int> list_merged;

    // as long as both left and right have elements in them,
    // determine which sublist has the smallest element in the front
    // and move that item into the merged sublist

    int iMerged = ind_A;

    while ( !sublist_left.empty() & !sublist_right.empty() ){

        if (sublist_left[0] < sublist_right[0]){
            // copy min value to a temp var
            tmpVal = sublist_left[0];
            // remove the min value from the left sublist
            sublist_left.erase( sublist_left.begin() );
        }
        else{
            // copy min value to a temp var
            tmpVal = sublist_right[0];
            // remove the min value from the right sublist
            sublist_right.erase( sublist_right.begin() );
        }
        // put the temp val in the correct place in the buffer
        // and increment iMerged index value
        buffer[iMerged++] = tmpVal;
        copy_count++;
    }

    // once either left or right sublist has become empty, move
    // any remaining elements to the merged list
    while (!sublist_left.empty()){
        buffer[iMerged++] = sublist_left[0];
        sublist_left.erase( sublist_left.begin() );
        copy_count++;
    }

    while (!sublist_right.empty()){
        buffer[iMerged++] = sublist_right[0];
        sublist_right.erase( sublist_right.begin() );
        copy_count++;
    }

}

void merge::display(){
    int i;
    for (i = 0; i<buffer.size(); i++)
        cout << setw(6) << buffer[i] << endl;
}

