#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
using namespace std;

class Review
{
private:
    string reviewerName;
    string *reviewText;

public:
    Review();
    Review(string rName, string rText)
    ~Review();
    void display() const;
    void save(ofstream &out) const;
    void setReview(string rText);
};

#endif
