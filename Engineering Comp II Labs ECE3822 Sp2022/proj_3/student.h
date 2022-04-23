#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;
class student{
private:
    //student's attributes
    string firstName;    //student's first name
    string lastName;    //student's last name 
    int studentId;      //student's Id
    float studentGpa;     //student's GPA
    string major;       //student's major
public:
    //constructor
    //student();      //default constructor
    student(string, string, int, float, string);      
    //getters for student's attributes
    string getName();       //returns full name
    string getFirstName();  //returns first name of student    
    string getLastName();   //returns last name of student    
    int getID();            //returns student's id
    float getGPA();         //returns student's GPA
    string getMajor();      //returns student's Major
};

#endif