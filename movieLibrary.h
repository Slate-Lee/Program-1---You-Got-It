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
    void import(string);
    void display();
    void add();
    void save(string);
    
    // to access the private attributes for test case
    string getTitle() const { return title; }
    string getDirector() const { return director; }
    int getYear() const { return year; }
    float getRating() const { return rating; }

};

#endif