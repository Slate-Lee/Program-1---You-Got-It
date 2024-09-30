#ifndef MOVIELIBRARY_H
#define MOVIELIBRARY_H

#include "movie.h"

class MovieLibrary
{
private:
    Movie **movies;
    int numOfMovies;

public:
    MovieLibrary();
    ~MovieLibrary();
    void import(string);
    void display();
    void add();
    void save(string);
};

#endif