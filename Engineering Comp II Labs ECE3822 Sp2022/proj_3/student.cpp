#include<iostream>
#include"student.h"
using namespace std;
//----------------------------------------------------------------------------------
//STUDENT CLASS
//----------------------------------------------------------------------------------
//constructor for type student
/*
student::student(){
    firstName="n/a";//student's First Name
    lastName="n/a";  //sutdent's Last Name 
    studentId=0;   //student's ID
    studentGpa=0; //student's GPA
    major="n/a";      //student's Major
}
*/
student::student(string first="n/a", string last="n/a",int id=0, float gpa=0, string maj="n/a"){
    firstName=first;//student's First Name
    lastName=last;  //sutdent's Last Name 
    studentId=id;   //student's ID
    studentGpa=gpa; //student's GPA
    major=maj;      //student's Major
}

//getter for student's full name
string student::getName(){ 
    string name= firstName+" "+lastName; //combines the first and last name into a name and returns it
    return name;
}

//getter for student's first name
string student::getLastName(){ 
    return lastName;
}

//getter for student's last name
string student::getFirstName(){ 
    return firstName;
}

//getter for student's id
int student::getID(){ 
    return studentId;
}

//getter for student's gpa
float student::getGPA(){ 
    return studentGpa;
}

//getter for student's major
string student::getMajor(){ 
    return major;
}

