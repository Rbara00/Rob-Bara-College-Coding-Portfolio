#include<iostream>
#include<thread>
#include<fstream>
#include<vector>
#include<chrono>
#include"queue.h"

/*I still have an issue where it my program crashes sometimes on the long file due to "double free or corruption (out)"
  but other times it works. I tried to use the debugger and I know it crashes at line 66, because it enters the getID()
  function and crashes at the return statement within my student class file. But also this is after it has already inserted
  multiple student into the hash table, so I am unsure if it just is not exiting the while loop when the queue becomes empty, 
  and over indexing, or if it is something else. I tried a few things to fix it but ultimately wasn't able to figure it out,
  so I got rid of it and left it as it is now.
*/

using namespace std;
using namespace std::chrono;

/*proj_3.cpp
   Robert Bara
   tuj22026@temple.edu
   03/16/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This program is an implementation of a hash table. The hash table contains student records holding the student's
   name, id, GPA, and major. The table works by hashing the students based upon their ID. All the information regarding
   a student is loaded in from text files contianing the information. The information is then loaded into a queue called
   waitinglist and is fed into the hashtable as information fills the queue. The driver program then searches for a given
   target id, and if the id is located within the hash table, then the student's record is printed to the terminal.

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make all
    Run:    ./proj_3 <arg>  , where arg can be 0, 1, or 2, corresponding to which text file will be loaded in
                              0->student_data_short.txt
                              1->student_data_medium.txt
                              2->student_data.txt
*/

//--------------------------------------------------------------------
// Hash Table Class
//--------------------------------------------------------------------
class hashTable{
    private:
    vector<student*> *table; //table is a pointer to vectors of pointer to students
    int hash_function(int); //hash function generates key based upon the student's Id
    int array_len;          //size of the hash table

    public:
    hashTable(int);         //constructor for the hash table
    void insert(student*);   //insert a complete student record into the table by passing in pointer to student
    void print_student(int); //search for student and it present, print the information
    int size();             //returns the size of the hash table

};

//constructor for hash table with dynamic memory allocation
hashTable::hashTable(int n=100){
    array_len = n; //length of table is user defined or defaulted to 100
    table = new vector<student*>[array_len]; //creating a table that stores arrays of pointers to a student
}

//hash function takes in the student's id and mods it with size of table
int hashTable::hash_function(int id){
        int idx;   
        idx = (id*id+(id/3))+(id*2);
    return id % array_len;      //generating key based on student's id modded with array len
}

//inseting a student into the hashtable using a pointer to a student
void hashTable::insert(student* new_student){
    int stud_id=new_student->getID();
    int index = hash_function(stud_id); // Pass the student's id in to determine their index
    table[index].push_back(new_student);            // Insert the pointer to student into the specified index
}

//getter for the size of the hash table
int hashTable::size(){
    return array_len;
}

//search for student and if present, print the information
void hashTable::print_student(int target_id){
    bool found; //flag for validity of the student's record
    int i;      //the index at where the student is located
   //get the key for the specified id
    int index=hash_function(target_id);
    
    //Traverse the table's vector at specified key until the student ID is found
        for (i = 0; i < table[index].size() ; i++){
           // cout<<"Hi Im Rob: "<<i<<endl;
            int currId=table[index][i]->getID();    //get the current specified student's id
            if(currId==target_id){                  //compare if the current id matches the target id
                found=true;                         //set true if they are a match, break to print
                break;
            } 
        }
    //if the table did not contain the student's id, print not found 
    if(found==false) cout<<"\tStudent with ID: "<<target_id<<" Not found"<<endl;
    //otherwise print the student's record
    else{
        //Get the student's attributes for printing
        int printId=table[index][i]->getID();
        float printGPA=table[index][i]->getGPA();
        string printName=table[index][i]->getName();
        string printMaj=table[index][i]->getMajor();

        //print the student's information
        cout<<"\tStudent Name: "<<printName<<" ID: "<<printId<<" GPA: "<<printGPA<<" Major: "<<printMaj<<endl;
    }
}


//--------------------------------------------------------------------
// Driver Program
//--------------------------------------------------------------------

// You will need these global variables
queue waiting_list=queue();
hashTable student_db=hashTable();
// this controls the input timing. do not edit
bool stop_thread = false;
steady_clock::time_point t1 = steady_clock::now();
float t_elapsed(){
    return duration_cast<seconds>(steady_clock::now() - t1).count();
}

//This function processes the input data when they are avaliable in the waiting list
void process_input_data(){
    student* p_student=NULL;    //initialize pointer to null

    while (!stop_thread){
        // if there's data in the waiting list, remove it from the queue and insert into hash table
        if(waiting_list.empty()==false){
            //pop the pointer of a student off the back of the queue and set it to the p_student pointer
            p_student=waiting_list.pop_back();
            //insert a pointer to the student into the table 
            student_db.insert(p_student);
        }
    //otherwise do nothing, move on to next student when data is avaliable
    }
    cout<<"Data Finished Processing"<<endl;
}

//This function loads data out of the specified text file and places them into a queue for processing 
void load_data(string filename){
    string shared_path = "/data/courses/ece_3822/current/proj_3/";
    string filename_complete = shared_path + filename;

    // create local variables to stash the data for each person as it's
    // read from the file
    float arrival_time,gpa;
    string first,last,major;
    int id;

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    // start the thread that will wait for input data to arrive
    thread thr(process_input_data);

    clock_t t_start = clock();
    while (f_id >> arrival_time){
        // read data for the next person in the file
        f_id >> first;
        f_id >> last;
        f_id >> gpa;
        f_id >> id;
        f_id >> major;

        // wait until their data packet has 'arrived'
        while ( t_elapsed() < arrival_time){
            ;
        }

        // create a student with attributes name, id, gpa, major
        // pass a pointer to the student into the waiting list queue
        student* p_new_student= new student(first, last, id, gpa, major);
        // add the new student to the wait queue
        waiting_list.push_back(p_new_student);
    }

    f_id.close();       // close the data file
    stop_thread = true; // send a signal to the thread to stop running
    thr.join();         // wait for the thread to finish up
}

//main function
int main(int argc, char** argv){
    string filename;

    if (argc !=2 ){
        cout << "ERROR: include a command line arguement of 0, 1, or 2" << endl;
        return -1;
    }

    switch (stoi(argv[1])){
        case 0: filename = "student_data_short.txt"; break;
        case 1: filename = "student_data_medium.txt"; break;
        case 2: filename = "student_data.txt"; break;
    }
    
    //filename="student_data.txt";
    //initialize queue
    waiting_list.clear_all(); 
    //Display which file is being loaded
    cout<<"\nLoading Data from: "<<filename<<endl;
    load_data(filename);
    waiting_list.clear_all(); //clear queue now that data is processed

    // now that the data has been stored in the hash table, lets test hashtable lookup

    // search for the following student IDs
    //checking students
    cout<<"------------Lets check the table------------\n";
    cout<<"Target Id 1: 758289915"<<endl;
    student_db.print_student(758289915);
    cout<<"Target Id 2: 738779716"<<endl;
    student_db.print_student(738779716);
    cout<<"Target Id 3: 427980112"<<endl;
    student_db.print_student(427980112);
    cout<<"Target Id 4: 258399712"<<endl;
    student_db.print_student(258399712);
    cout<<"Target Id: 948140115"<<endl;
    student_db.print_student(948140115);

    return 0;
}