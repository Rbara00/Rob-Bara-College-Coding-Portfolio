#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"
#include<iostream>

using namespace std;
class customer{
private:
    int id;                         //customer's ID
    int numOfMovies;                //number of movies customer has watched
    list<int> watchedMovieIDs;      //list of the movie IDs the customer has watched
    
public:
    customer();                     //default constructor if the customer does not exist
    customer(int, int, list<int>);  //constructor for the customer and sets id, number of movies, and list of movies
    int getID();                    //getter for the customer's id
    int getNumMovies();             //getter for the number of movies the customer has watched
    list<int> getMovies();          //getter for the list of movie id's the customer has watched
};

#endif
