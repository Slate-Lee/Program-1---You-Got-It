#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
using namespace std;

class Review
{
private:
    string reviewerName;
    string *reviewText; // Dynamically allocated review text

public:
    // Constructors
    Review();

    Review(string rName, string rText);

    // Destructor
    ~Review();

    // Function to display review
    void display();

    // Function to save review to a file
    void save(ofstream &out);

    // Function to set the review text
    void setReview(string rText);
};

#endif
