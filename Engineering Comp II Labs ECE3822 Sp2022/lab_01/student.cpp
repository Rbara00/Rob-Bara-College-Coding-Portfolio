// INCLUDES - DO NOT EDIT
#include "student.h"
#include<string>
#include<iostream>
using namespace std;


//Method to display the student's name followed by testscore average
void student::display(){
    get_test_average(); //calling the getter method to find the student's average
    cout.precision(4);  //preparing to print the average as a float with 2 decimal places
    cout<<"Student:\t"<< name<<endl<<"Average:\t"<<test_average<< endl; //printing the student's name and average
    if(test_average==0) cout<<"This student has no testscores to compute an average."<<endl;
}

//Method that iterates through the testscore's vector, finds the sum, and computes the student's average
void student::compute_average(){
    //initializing sum and size of vector
    float sum=0;
    float score_size=test_scores.size();
        for (int i=0;i<score_size;i++){
            sum=sum+test_scores.at(i);//add current testscore to sum
        }
    //calculating the average by dividing sum by the size of the vector
    test_average=sum/score_size;
}

//Getter method for accessing the test_average
float student::get_test_average(){
     //If testscores are avaliable for the student, call method to calculate the average
    if(!test_scores.empty())
        compute_average();
    return test_average;    //return the student's average
}

//apprehends another test score value to the total testscore's vector
void student::add_new_test(int y){
    test_scores.push_back(y);   //pushes new value from the back
}

//constructor for student, intializes name, scores, and average
student::student(string x){
    name=x;               //set student's name to string passed in
    test_scores.clear(); //intiialize the testscore vector
    test_average=0;     //initialize the student's average to 0

}
