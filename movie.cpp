#include "movie.h"

/*
Functions needed
    // declaration of member function
        Movie :: Movie(){}
    // display
        Movie :: display(){}
    // save
        Movie :: save(){}
*/

Movie::Movie(string cTitle, string cDirector, int cYear, double cRating) {

    this->title=cTitle;
    this->director=cDirector;
    this->year=cYear;
    this->rating=cRating;

    

}