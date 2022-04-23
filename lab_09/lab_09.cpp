#include<iostream>
#include<iomanip>
#include <chrono>
#include <vector>
#include "heap.h"
#include "bubble.h"
#include "merge.h"
#include "RNG.h"
/*lab_09.cpp
   Robert Bara
   tuj22026@temple.edu
   04/01/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This file utilizes three different sorting algorithms that have been implemented into respective classes,
   heap, bubble, and merge sorting. The program runs all three sorts on a set of randomly generated data and
   computes the number of swaps performed for the algorithm, as well as the average time it takes to run this
   type of algorithm in microseconds. This is calculated by recording the time stamps between when the sorting
   algorithm began and ended, and obtaining the difference, then dividing this time by the number of trials per
   size. The output will be differnet each time, but further analysis can be seen in the excel file "lab_09Graph.xlsx",
   within this directory.

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make lab_09
    Run:    ./lab_09
*/
using namespace std;
using namespace std::chrono;

void runTime(){
    RNG R(10000);
    long int swaps_heap;
    long int swaps_bubl;
    long int swaps_merg;

    int n_trials_per_size=100;
    int buffer_size;
    int buffer_size_array[] = {50, 100, 200, 500, 1000, 2000};

    int array_len = sizeof(buffer_size_array) / sizeof(int);

    binary_heap data_heap;
    bubble_sort data_bubl;
    merge       data_merg;


    // define variables of time "time_point"
    steady_clock::time_point t1a;
    steady_clock::time_point t1b;
    steady_clock::time_point t1c;
    steady_clock::time_point t2a;
    steady_clock::time_point t2b;
    steady_clock::time_point t2c;
    

    // define other variables
    int n_cycles = 1000000;

    cout
    << setw(6) << "size"
    << "\t" << setw(12) << "swaps:heap"
    << "\t" << setw(12) << "swaps:bubl"
    << "\t" << setw(12) << "swaps:merg"
    << "\t"<<  setw(12) << "Avg Time:Heap"
    <<"\t" <<  setw(12) <<"Avg Time:bubl"
    <<"\t" <<  setw(12) << "Avg Time:merg"
    << endl;

    for (int k = 0; k<array_len; k++){
    
        buffer_size = buffer_size_array[k];

        swaps_heap = 0;
        swaps_bubl = 0;
        swaps_merg = 0;

        for (int j = 0 ;j<n_trials_per_size;j++){
            
            R.reset();
            data_heap.reset(buffer_size);
            data_bubl.reset(buffer_size);
            data_merg.reset();

            for (int i = 0; i<buffer_size; i++){
                int val = R.gen();
                data_heap.insert (val);
                data_bubl.insert (val);
                data_merg.insert (val);
            }

            //sort and get elapsed times
            t1a = steady_clock::now();          //grab the start time
            swaps_heap += data_heap.sort();
            t2a = steady_clock::now();          //grab the end time

            t1b = steady_clock::now();          //grab the start time   
            swaps_bubl += data_bubl.sort();
            t2b = steady_clock::now();          //grab the end time
            
            t1c = steady_clock::now();          //grab the start time
            swaps_merg += data_merg.sort();
            t2c = steady_clock::now();          //grab the end time

        }
        
        //compute the average number of swaps for each sort
        float avg_heap = (float) swaps_heap / n_trials_per_size;
        float avg_bubl = (float) swaps_bubl / n_trials_per_size;
        float avg_merg = (float) swaps_merg / n_trials_per_size;
        
        // compute the elapsed time in microseconds
        float t_elapsed_heap = duration_cast<microseconds>(t2a - t1a).count();
        float t_elapsed_bubl = duration_cast<microseconds>(t2b - t1b).count();
        float t_elapsed_merg = duration_cast<microseconds>(t2c- t1c).count();
        
        //printing analysis
        cout << fixed
        << setprecision(2)
        << setw(6) << buffer_size 
        << "\t" << setw(12) <<avg_heap 
        << "\t" << setw(12) << avg_bubl 
        << "\t" << setw(12) << avg_merg
        << "\t"<<setprecision(6)<<setw(12)<<(float)t_elapsed_heap/n_trials_per_size
        << "\t"<<setw(12)<<(float)t_elapsed_bubl/n_trials_per_size
        << "\t"<<setw(12)<<(float)t_elapsed_merg/n_trials_per_size
        <<endl;
        
    } 
}

//driver program
int main(int argc, char** argv){
    //create a buffer and compute the swaps and run time as a function of the number of points being sorted
    runTime();

    //Explanation about Swaps versus Average Time for each sort
    cout<<"\nI exported this output to excel and generated a graph under lab_09Graph.xlsx\n"
        <<"By selecting which data is avaliable on the graph using excel, you can examine each individual data\n" 
        <<"series and observe that the number of swaps create the same correlation as the average times for\n"
        <<"each algorithm. Furthermore, I took the ratio increases in excel and we can see that increase as\n" 
        <<"more points are added are similar within error. Both are ways of recording the complexity, the time \n"
        <<"shows when a sorting process begins and ends, then divides that value by the number of trials performed,\n"
        <<"the difference is one is telling us the physical number of swaps to sort, while the other is telling us\n"
        <<"how long the process of sorting and swapping typically takes. The elapsed time recorded is based upon\n"
        <<"the actual time recorded to perform the swap based upon the randomly generated data.\n"<<endl;

    return 0;
    
}
