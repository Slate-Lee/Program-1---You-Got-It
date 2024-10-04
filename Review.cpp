#include "review.h"

// Default constructor
Review::Review()
{
    reviewerName = "";
    reviewText = nullptr; // Initially no review
}

// Parametrized constructor
Review::Review(string rName, string rText)
{
    reviewerName = rName;
    reviewText = new string(rText); // Dynamically allocate review text
}

// Destructor
Review::~Review()
{
    delete reviewText; // Free the dynamically allocated memory
}

// Display review information
void Review::display()
{
    cout << "\nReviewer: " << reviewerName;
    if (reviewText)
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
    cout << reviewerName << "\n";
    if (reviewText)
    {
        cout << *reviewText;
    }
    else
    {
        cout << "No review available.";
    }
}

// Set the review text
void Review::setReview(string rText)
{
    if (reviewText)
    {
        delete reviewText; // Free previous memory if exists
    }
    reviewText = new string(rText); // Allocate new review text
}
