// 
// Lab 00
// Robert Bara
// 1/12/2022
//
// This c++ program reads in a list of randomly generated numbers from a file and computes the average
// by storing them to an array and finding the sum, from this the average is calculated by dividing by the
// number of elements within the array
//
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    // step 1 init variables
    int i=0;        //array index, at the end of the loop it will be the total number of elements
    int arr[1000];  //declaring an array of 1000
    int s = 0;      //sum of all numbers in array
    double avg = 0; //average=sum/number of elements in array
    string line;    //for reading current string in file 
    int val;        //typecasts the value from file into an integer

    // step 2 open file
    ifstream file_id("lab_00_data.txt");

    // step 3 read values from file   
    while (getline(file_id,line)){
        // read a line from file and typecast as int
        val = stof(line);
        // store the int in array
        arr[i] = val; 
        // increment the array counter til all data is read
        i++;
    }

    // step 4 find the sum of every five elements
        for (i=0 ; i<1000; i++) s =s + arr[i];

    // step 5 calculating the average, i is the last index of the array
    // which corresponds to the total number of elements
    avg=s/i;

    // step 6 print value
    cout.precision(3);
    cout << "The average value is " << avg << endl;
    return 0;
}