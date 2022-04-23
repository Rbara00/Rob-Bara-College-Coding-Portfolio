#ifndef MOVIE_H
#define MOVIE_H

#include<list>
#include<vector>
#include<iostream>

class movie{
private:
    int id;     //movie's id
    
public:
    movie();        //default constructor for when movie does not exist
    movie(int);     //constructor for the movie, passes in the id and sets the view count
    int getID();    //getter for the movie's id
};

#endif
