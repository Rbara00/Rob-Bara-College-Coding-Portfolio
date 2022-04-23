#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int main(){

    /* 
    This function shows us how to use the chrono toolbox
    to measure execution times at very fine resolution.
    */

    // define variables of time "time_point"
    steady_clock::time_point t1;
    steady_clock::time_point t2;

    // define other variables
    float t_elapsed;
    int n_cycles = 1000000;

    // grab the start time
    t1 = steady_clock::now();

    // do some stuff that you want to time
    for (int i = 0; i<n_cycles; i++){
        ;
    }

    // grab the end time
    t2 = steady_clock::now();

    // compute the elapsed time in microseconds
    t_elapsed_heap = duration_cast<microseconds>(t2 - t1).count();

    // output the results
    cout << "\n" << endl;
    cout << "elapsed time = " << t_elapsed << " microseconds" << endl;
    cout << "the avg time per cycle was " << t_elapsed/n_cycles << " microseconds" << endl;
    cout << "\n" << endl;

    return 0;
}

