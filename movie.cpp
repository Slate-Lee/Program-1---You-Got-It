#include "movie.h"

Movie::Movie()
{
    title = "";
    director = "";
    year = 0;
    rating = 0.0;
}

Movie::Movie(string tTitle, string tDirector, int tYear, float tRating)
{
    title = tTitle;
    director = tDirector;
    year = tYear;
    rating = tRating;
};

void Movie::display()
{
    cout << "\nTITLE: " << title;
    cout << "\nDIRECTOR: " << director;
    cout << "\nDATE: " << year;
    cout << "\nRATING: " << rating << endl;
};

void Movie::save(ofstream &out)
{
    out << title << "\n";
    out << director << "\n";
    out << year << "\n";
    out << rating;
}