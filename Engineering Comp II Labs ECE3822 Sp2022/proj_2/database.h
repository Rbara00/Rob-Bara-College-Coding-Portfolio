#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include"movie.h"
#include"customer.h"

using namespace std;

class database{
private:
    list<movie> movies;                 //List to keep track of all movies that have been watched
    list<customer> customers;           //List to keep track of the amount of customers there are
    void analyze_data(list<int>);       //converts the data into their attributes
    void print_info(int,int,list<int>); //prints the information of the customer in a nice format
    customer check_customer(int);       //checks if the specified ID matches a customer's ID

public:
    void load_data(std::string);        //responsible for loading all data from a string into a list
    void print_all();                   //prints every customer in order
    void print_customer(int);           //print a specific customer based on the id
    void print_views(int);              //print the viewcount of a specific movie based on the id
};

#endif
