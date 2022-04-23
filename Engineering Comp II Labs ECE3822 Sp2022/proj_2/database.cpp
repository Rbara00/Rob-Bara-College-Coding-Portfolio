#include "database.h"
#include<iostream>
#include<fstream>
using namespace std;

//Function loads in data from a file and places data into a list
void database::load_data(std::string filename){
    ifstream inputFile;     //data file to be read from
    int data;               //variable that data is written to
    list<int> info;         //store all data to a list to be separated into objects
    
    // step 0: Open the file 
    inputFile.open(filename);

    // step 1: As long as there is data to be read, store every line as a list
    while ( inputFile >> data ){
        //Read data and load into a list
        info.push_back(data);
    }

    // step 2: When reading is done, close file
    inputFile.close();
    
    // step 3: Pass list of data into function to separate into customer's objects
    analyze_data(info);
}

// This function's purpose is to convert the data that was read into attributes for a customer
// as well as keep track of what movies have been viewed
void database::analyze_data(std::list<int> info){
    int id=0;               //for obtaining the customer's id
    int numOfMovies=0;      //for obtaining how many movies a customer has watched
    int i=0;                //counter for sorting which movie ID's the customer has watched
    movie current_movie;
    list<int> watchedIds;   //This is a list for the movies the customer has watched
    movies.clear();

    // Step 0: Run as long as there is data in the list
    while (info.empty()==false){
        //step 1: get customer's id and initialize vector for the movies they have watched
        id=info.front();
        watchedIds.clear();                 //initialize the vector of movies the customer has watched

        //step 2: get number of movies theyve watched, this is the size of the list of movies
        info.pop_front();                   //remove data element from the front of list
        numOfMovies=info.front();           //the number of movies a customer has watched is placed after their ID        

        //step 3: create a while loop to pass in the next x amount of lines as movie ids
        info.pop_front();                   //remove data element from front of list
        for(int i=0;i<numOfMovies;i++){
            //priority logic, break loop if there is no more data
            if(info.empty()) break;

            //step 3.1: Get the next movie ID and create a movie variable            
            int movieID=info.front();       //temp variable to pass in movie ID
            current_movie=movie(movieID);   //create a movie based on the id
        
            //step 3.2: Pass customer's movie IDs into a list of their watched movies and the total movies avaliable 
            watchedIds.push_back(movieID);  //for the customer's watched movies
            movies.push_back(movieID);      //for the store's database of movies
            info.pop_front();               //remove a data element to get the next movie ID 
        }
        //step 4: create a customer based on attributes
        customer person=customer(id,numOfMovies,watchedIds);
        //step 5: store customer into a list/vector?
        customers.push_back(person);    //for a vector of customers
        watchedIds.clear();             //clear temp list for next customer
    }
}

//This function prints the information of the customer in a nice format
void database::print_info(int id, int numMovies, list<int>movieIds){
    //step 1: Print which customer it is
     cout<<"\nCustomer "<<id<<" watched ";
    //step 2: Loop for the amount of movie's they've watched
     for(int i=0;i<numMovies;i++){
         //step 2.1: Get the movie Id in order and print it
         int curr_movieId=movieIds.front();
         cout<<curr_movieId<<" ";
         movieIds.pop_front();
     }
}

//This function prints every customer's information
void database::print_all(){
    //priority logic, if there are no customers to print, dont print
    if(customers.empty()==true) cout<<"No customers on file";
    else{
        list<customer> tmp_customers=customers;
    cout<<"Printing all customers:"<<endl;
        //step 0: Loop until there are no more customers in the list
        while(tmp_customers.empty()==false){
        //step 1: Get the current customer
        customer curr_cust=tmp_customers.front();
        //step 1.2: Get the customer's ID, number of movies they've watched and the movies' IDs
        int id=curr_cust.getID();
        int numMovies=curr_cust.getNumMovies();
        list<int> movieIds=curr_cust.getMovies();
        //step 2: Print all the customer's info
        print_info(id,numMovies,movieIds);
        //step 3: update to print the next customer
        tmp_customers.pop_front();
        }
    }
}

//This function checks if the specified ID belongs to a valid customer and returns that customer
customer database::check_customer(int id){
    //define variables for printing and getting customer
    int customers_id;
    customer curr_cust;
    int length=customers.size();
    list<customer> tmp_customers=customers;
    //step 0: Loop through all customers
    for(int i=0;i<length;i++){
        //step 1: Get the current customer
        curr_cust=tmp_customers.front();
        //step 2: Check if the customer's ID is a match        
        customers_id=curr_cust.getID();
        //step 2.1: If it is a match return the customer
        if(id==customers_id){
            return curr_cust;
        } 
        //step 2.2: If if it is not a match, keep iterating 
        tmp_customers.pop_front();
    }
        //step 2.3: If none are a match return an invalid customer
        return curr_cust=customer();
}

//This function prints the specified customer based on the passed in ID
void database::print_customer(int id){
    //define variables for printing and getting customer
    int customers_id, numMovies;
    customer curr_cust;
    list<int> movieIds;
    int length=customers.size();

    //step 0: Check if there is customers to search through
    if(customers.empty()==true) cout<<"No customers on file";
    //step 1:Check if the passed in ID matches any customer's id
    curr_cust=check_customer(id);
    customers_id=curr_cust.getID();
    //step 2: If the ID does not match print invalid
    if(customers_id==0) cout<<"invalid customer";
    //If the ID does match, print the customer
    else{
        //getting the customer's movies
        numMovies=curr_cust.getNumMovies();
        movieIds=curr_cust.getMovies();
        //step 3: Print which customer it is
        print_info(customers_id,numMovies,movieIds);
    }
}

//This function prints the view count of the specified movie
void database::print_views(int movieId){
    movie curr_Movie;
    int viewCount=0;
    int curr_id=0;
    int length=movies.size();
    list<movie> tmp_movies=movies;
    //Step 0: Check if there are movies to search through
    if(tmp_movies.empty()==true) cout<<"No Movie with that id on file";
    //Step 1: Loop through all movies
    for(int i=0;i<length;i++){
        //get the current movie
        curr_Movie=tmp_movies.front();
        curr_id=curr_Movie.getID();
        //step 2: Check if the ID is a match
        if(movieId==curr_id){ 
            //step 3: When the movie is found, get the ID and break
            viewCount=viewCount+1;
        }
        //Get the next movie for the loop to continue
        tmp_movies.pop_front();     
    }
    //step 4: Print the movie and viewcount
    cout<<"movie "<<movieId<<" was watched "<<viewCount<<" time(s)";
}