/*
    review.h
    Header file for the review class
*/

#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// class definition
class Review
{
private:
    string reviewerName;
    string *reviewText;

public:
    Review();
    Review(string rName, string rText);
    ~Review();
    void display();
    void save(ofstream &out);
    void setReview(string rText);
};

#endif