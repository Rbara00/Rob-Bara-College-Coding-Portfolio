#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<vector>
using namespace std;

// DO NOT EVEN THINK ABOUT EDITING THIS FILE

class student{
private:
    string name;                // student's name
    vector<int> test_scores;    // a vector (not an array) of test scores
    float test_average;         // the average of the test scores
    void compute_average();     // a *private* function that computes the avg test score and saves it in test_average

public:
    student(string);            // constructor -> accepts the student's name as input
    void add_new_test(int);     // append a new test score to the vector of test scores
    void display();             // display the student's name and average test score
    float get_test_average();   // return the value of the student's average test score
};

#endif
