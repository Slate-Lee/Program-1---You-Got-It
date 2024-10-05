/*
    movieLibrary.h
    Header file for the movie library class
*/

#ifndef MOVIELIBRARY_H
#define MOVIELIBRARY_H

#include "movie.h"

// class definition
class MovieLibrary
{
private:
    Movie **movies;
    int numOfMovies;

public:
    MovieLibrary();
    ~MovieLibrary();
    void import();
    void display();
    void add();
    void save();
};

#endif