/* lab_main.cpp

   Rob Bara
   tuj22026@temple.edu
   1/19/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   student.h:   Header file containing all private/public definitions to the student class
   student.cpp: Class file containing constructor and methods to keep track of student's test scores, 
                calculate the average, and display the results
   lab_01.cpp:  Driver file for testing the Student class
   Makefile:    Compiles each file in the correct order, outputs executabe to run the driver 

   Usage:
   COMMANDS FOR HOW TO COMPILE AND RUN:
   Compiling:               make lab_01
   Clean the compile type:  make clean

   Running: ./lab_01 (argument)
            Flags for running include 0,1,2,3 which will execute corresponding the testcase number,
            for example: ./lab_01 0      will result  in running testcase_0 checking the student alice's information 
*/

// INCLUDES - DO NOT EDIT
#include<iostream>
#include<string>
#include<stdlib.h>
#include "student.h"
using namespace std;

/**
   Create a new student called Alice and give her two test scores,
   then display the result
*/

void testcase_0(){

    // DO NOT EDIT THIS FUNCTION
    student student_0("alice");
    student_0.add_new_test(98);
    student_0.add_new_test(95);
    student_0.display();
}


/**
   Create a new student called bob and don't give him *any* test
   scores, then display the result
*/
void testcase_1(){

    // DO NOT EDIT THIS FUNCTION
    student student_1("bob");
    student_1.display();
}

/**
   Create a pointer to a new student named charlie
   add three test scores, then display the result
*/
void testcase_2(){

    // DO NOT EDIT THIS FUNCTION
    student *student_2 = new student("charlie");
    student_2->add_new_test(55);
    student_2->add_new_test(47);
    student_2->add_new_test(68);
    student_2->display();
}

// Work with an array of pointers to students
void testcase_3(){

    student *myClass[4];//declare an array of 4 pointers to students

    // For each of the pointers in myClass, create a new student (you can pick
    // the names), and add at least one score.

    myClass[0]=new student("Rob");      //First Element of array points to student created as Rob
    myClass[0]->add_new_test(100);      //First Element student is given a testscore
    myClass[1]=new student("Rob2");     //Second Element of array points to student created as Rob2
    myClass[1]->add_new_test(80);       //Second Element student is given a testscore
    myClass[1]->add_new_test(93);       //Second Element student is given a testscore
    myClass[2]=new student("Evil Rob"); //Third Element of array points to student created as Evil Rob
    myClass[2]->add_new_test(5);        //Third Element student is given a testscore
    myClass[3]=new student("Bor");      //Fourth Element of array points to student created as backwards rob, Bor
    myClass[3]->add_new_test(77);       //Fourth Element student is given a testscore

    
    //Loop iterates across array of pointers. At the current pointer, display the current student it is pointing at's information 
    for (int i = 0; i < 4 ; i ++)
    	myClass[i] -> display();
}



int main(int argc, char ** argv){

    // DON'T EVEN THINK ABOUT EDITING THIS FUNCTION

    string errStr = "ERROR: provide a commandline arguement 0, 1, 2, or 3";
    
    // Accept user input and branch accordingly. 
    int option;
    if (argc==2)
        // make sure the user has given an input
    	option = atoi(argv[1]);
    else{
    	cout << "\n" + errStr + "\n" << endl;
	return 1;
    }

    switch (option){
    case 0: testcase_0(); break;
    case 1: testcase_1(); break;
    case 2: testcase_2(); break;
    case 3: testcase_3(); break;
    default: cout << errStr << endl; break;
    }
    
    return 0;
}
