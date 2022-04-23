/* 
   PROJ_2.CPP
   Rob Bara
   tuj22026@temple.edu
   2/16/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This program analyzes information from a data file regarding customers watching movies
   and keeps track of each customer and the movies they have watched based upon the ID of the
   customer and ID of the movie. From that a database based upon the customers and movies
   are constructed and the customers information regarding their id and movies they have
   watched may be printed.

   Usage:
   Compiling: make all
   running: ./proj2 data_file_num test_file_num optional_id_num
*/

#include<iostream>
#include "database.h"
using namespace std;

void get_user_params(int, char**, int*, int*, int*);

int main(int argc, char** argv){

    // define vars for loading data
    string shared_path = "/data/courses/ece_3822/current/proj_2/";
    string filename;

    // define other vars
    int data_file_num;
    int test_case_num;
    int id_number;

    // get the user's input preferences for file number and testcase number
    get_user_params(argc, argv, &data_file_num, &test_case_num, &id_number);

    // build the appropriate filename
    switch (data_file_num){
    case(1): filename = shared_path + "dataFile1.txt"; break;
    case(2): filename = shared_path + "dataFile2.txt"; break;
    case(3): filename = shared_path + "dataFile3.txt"; break;
    }

    database db;				// define the database
    db.load_data(filename);		// load the data into the database

    switch (test_case_num){
    case(1):					// testcase 1: print all the data
	cout << "\n----------Testcase 1----------" << endl;

	db.print_all();
	cout << "\n" << endl;
	break;

    case(2):					// testcase 2: print all data for one customer
	cout << "\n----------Testcase 2----------" << endl;

	db.print_customer(id_number);
	cout << "\n" << endl;
	break;
	
    case(3):					// testcase 3: print all watchers of one movie
	cout << "\n----------Testcase 3----------" << endl;

	db.print_views(id_number);
	cout << "\n" << endl;
	break;
    }

    return 0;
}

void get_user_params(int argc, char** argv, int* pdata_file_num, int *ptest_case_num, int *pid_number){

    // define error messages
    string err_msg_1 = "\nError: Usage ./proj2 data_file_num test_case_num id_number\n";
    string err_msg_2 = "\nError: data_file_num must be 1, 2, or 3\n";
    string err_msg_3 = "\nError: test_case_num must be 1, 2, or 3\n";

    // make sure there at least two parameters
    if (argc < 3){
	cout << err_msg_1 << endl;
	exit;
    }

    else{
	*pdata_file_num = atoi(argv[1]);
	*ptest_case_num = atoi(argv[2]);
	if (*pdata_file_num < 1 || *pdata_file_num > 3){
	    cout << err_msg_2 << endl;
	    exit;
	}

	if (*ptest_case_num < 1 || *ptest_case_num > 3){
	    cout << err_msg_3 << endl;
	    exit;
	}

	if (*ptest_case_num != 1)
	    if (argc!=4){
		cout << err_msg_1 << endl;
		exit;
	    }
	    else{
		*pid_number = atoi(argv[3]);
	    }
	
    }
}
