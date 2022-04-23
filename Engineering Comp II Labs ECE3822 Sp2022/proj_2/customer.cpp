#include "customer.h"
#include<iostream>
#include<fstream>
using namespace std;

//default constructor for customer, really this customer does not exist
customer::customer(){
    id=0;
    numOfMovies=0;
    watchedMovieIDs.clear();
}

//constructor for customer that passes in the customer's id, number of movies they have watched, and those movie's ids
customer::customer(int theirId, int aNumOfMovies, list<int>watchedMovies){
    id=theirId;                     //pass in id for the customer
    numOfMovies=aNumOfMovies;       //pass number of movies the customer has watched
    watchedMovieIDs=watchedMovies;  //pass in the movie IDs of the customer's watched movies
}

//getter for customer's id
int customer::getID(){             
    return id;
}

//getter for the number of movies the customer has watched
int customer::getNumMovies(){
    return numOfMovies;
}

//getter for list of movies the customer has watched
list<int> customer::getMovies(){
    return watchedMovieIDs;
}
