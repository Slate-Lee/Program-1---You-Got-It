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
void Review::display() const
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
void Review::save(ofstream &out) const
{
    cout << reviewerName << endl;
    if (reviewText)
    {
        cout << *reviewText;
    }
    else
    {
        cout << "No movie review available.";
    }
}

// Set review text
void Review::setReview(string rText)
{
    if (reviewText)
    {
        delete reviewText;
    }
    reviewText = new string(rText);
}
