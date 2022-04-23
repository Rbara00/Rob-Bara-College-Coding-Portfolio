#include "movie.h"
#include<iostream>
#include<fstream>
using namespace std;

//default constructor for movie. If this movie is created then the movie does not exist in the database
movie::movie(){
    id=0;    
}

//constructor for movie. If a movie is created then it has been viewed atleast once by a customer
movie::movie(int movieId){
    id=movieId;    //set the movie id
}

//getter for te movie's id
int movie::getID(){
    return id;
}
