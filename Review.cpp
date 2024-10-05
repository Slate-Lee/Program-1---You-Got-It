/*
    review.cpp
    Defines the functions for the review class
*/

#include "review.h"

// Default constructor
Review::Review()
{
    reviewerName = "";
    reviewText = nullptr; 
}

// Parametrized constructor
Review::Review(string rName, string rText)
{
    reviewerName = rName;
    reviewText = new string(rText); 
}

// Destructor
Review::~Review()
{
    delete reviewText;
}

// Display review information
void Review::display()
{
    cout << "\nReviewer: " << reviewerName;
    if (reviewText && !reviewText->empty())
    {
        cout << "\nReview: " << *reviewText;
    }
    else
    {
        cout << "\nNo review available.";
    }
    cout << endl;
}

// Save review information to a file
void Review::save(ofstream &out)
{
    if (reviewText && !reviewText->empty())
    {
        out << reviewerName << endl;
        out << *reviewText << endl;
    }
    else
    {
        out << "No review available.";
    }
}

// Set the review text
void Review::setReview(string rText)
{
    if (reviewText)
    {
        delete reviewText;
    }
    reviewText = new string(rText); 
}