#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Movie
{

private:
    string title;
    string director;
    int year;
    float rating;

public:
    Movie();
    Movie(string, string, int, float);
    void display();
    void save(ofstream&);
};

#endif