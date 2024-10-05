/*
    movie.cpp
    Defines the functions for the movie class
*/

#include "movie.h"

// Default constructor
Movie::Movie()
{
    title = "";
    director = "";
    year = 0;
    rating = 0.0;
    movieReview = nullptr; // Initialize review to nullptr
}

// Parametrized constructor
Movie::Movie(string tTitle, string tDirector, int tYear, float tRating)
{
    title = tTitle;
    director = tDirector;
    year = tYear;
    rating = tRating;
    movieReview = nullptr; // Initialize review to nullptr
}

// Destructor to free dynamically allocated Review
Movie::~Movie()
{
    delete movieReview;
}

// Display movie and review information
void Movie::display()
{
    cout << "\nTITLE: " << title;
    cout << "\nDIRECTOR: " << director;
    cout << "\nDATE: " << year;
    cout << "\nRATING: " << rating << endl;
    if (movieReview)
    {
        movieReview->display(); // Display the review if it exists
    }
}

// Save movie and review information to a file
void Movie::save(ofstream &out)
{
    out << title << "\n";
    out << director << "\n";
    out << year << "\n";
    out << rating << "\n";

    if (movieReview)
    {
        movieReview->save(out); // Save the review if it exists
    }
}

// Function to add or update a review for the movie
void Movie::addReview(string reviewerName, string reviewText)
{
    if (movieReview)
    {
        delete movieReview; // Delete the old review if it exists
    }
    movieReview = new Review(reviewerName, reviewText); // Create a new review
}