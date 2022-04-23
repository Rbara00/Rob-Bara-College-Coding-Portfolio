/*lab_10.cpp
   Robert Bara
   tuj22026@temple.edu
   04/06/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This program allows for a class to be generated based upon students with name and id attributes. 
   The program allows for a student to be inserted into the class, sort the students by id or name,
   print the students in the corresponding order, or reset the class. 

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make all
    Run:    ./lab_10
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct student_pair {
    int id;
    string name;
};

class my_class {
   private:
    const static int list_len = 10;
    student_pair students[list_len];
    int ctr = 0;

   public:
    void add_student(int id, string name);
    void sort_by_id();
    void sort_by_name();
    void print_list();
    void reset();
    void swap(int, int);
};

// reset the list
void my_class::reset() { ctr = 0; }

// print list
void my_class::print_list() {
    cout << "List of students: " << endl;
    cout << "ID\tName" << endl;
    for (int i = 0; i < ctr; i++) {
        cout << students[i].id << "\t" << students[i].name << endl;
    }
    cout << "\n" << endl;
}

// Add a student to the class
void my_class::add_student(int id, string name) {
    students[ctr++] = {id, name};
}

/* You said you do not care about efficiency for this lab, and  
   I have to be honest I've been pretty swamped this week, so
   I present to you the infamous bubble sort :)
*/
void my_class::sort_by_id() {
    // Repeat until all the class is sorted
    for(int j=0;j<list_len;j++){
        //iterate through class and check current id with next id
        for(int i=0;i<list_len-1;i++){
            //if the next student's id comes before the current student's id, swap
            if(students[i].id>students[i+1].id)
                swap(i,i+1);
        }
    }
}

// sorts the students in order of name
void my_class::sort_by_name() {
    // Repeat until all the class is sorted
    for(int j=0;j<list_len;j++){
        //iterate through class and check current name with next name
        for(int i=0;i<list_len-1;i++){
            //if the next student's name comes before the current student's name, swap
            if(students[i].name>students[i+1].name)
                swap(i,i+1);
        }
    }
}

// swaps two students in the class
void my_class::swap(int i,int j){
    student_pair tmp;
    tmp=students[j];
    students[j]=students[i];
    students[i]=tmp;
}

int main() {

    my_class class_1;

    for (int i = 0; i < 2; i++) {

        class_1.reset();

        class_1.add_student(9, "Clarence");
        class_1.add_student(7, "Susan");
        class_1.add_student(3, "Peter");
        class_1.add_student(4, "Paul");
        class_1.add_student(1, "John");
        class_1.add_student(6, "Chris");
        class_1.add_student(2, "Mary");
        class_1.add_student(8, "Thomas");
        class_1.add_student(10, "Francesca");
        class_1.add_student(5, "Alex");


        if (i==0){
            class_1.sort_by_id();
            cout << "\n************** Sorted by ID **************" << endl;
            class_1.print_list();
        }
        else{ // i==1
            class_1.sort_by_name();
            cout << "\n************** Sorted by name **************" << endl;
            class_1.print_list();
        }
        
    }

    return 0;
}