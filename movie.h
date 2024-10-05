/*
    movie.h
    Header file for the movie class
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <fstream>
#include "review.h"

using namespace std;

// class definition
class Movie
{
private:
    string title;
    string director;
    int year;
    float rating;
    Review *movieReview;

public:
    Movie();
    Movie(string, string, int, float);
    void display();
    void save(ofstream&);
    ~Movie(); 
    void addReview(string reviewerName, string reviewText);
};

#endif