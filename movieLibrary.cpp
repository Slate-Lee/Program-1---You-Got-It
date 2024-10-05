/*
    movieLibrary.cpp
    Defines the functions for the movie library class
*/

#include "movieLibrary.h"
#include <fstream>

MovieLibrary::MovieLibrary()
{
    movies = nullptr;
    numOfMovies = 0;
};

// Destructor
MovieLibrary::~MovieLibrary()
{
    for (int i = 0; i < numOfMovies; i++)
    {
        delete movies[i];
    }
    delete movies;
};

void MovieLibrary::import()
{
    // definitions
    ifstream myFile;
    string line;
    string fileName;

    string rTitle;
    string rDirector;
    int rYear;
    float rRating;

    string reviewerName, reviewText;

    int tempCount = 0;
    
    cin.ignore();

    if (numOfMovies < 1)
    {
        cout << "\nType name of file to import: ";
        getline(cin, fileName);
        
        // opens file
        myFile.open(fileName, ios::in);
        if (myFile.is_open())
        {
            // first loop which counts the number of lines
            while (!myFile.eof())
            {
                // goes through lines to get the following:
                getline(myFile, rTitle);    // title
                getline(myFile, rDirector); // director
                myFile >> rYear;            // year
                myFile >> rRating;          // rating
                myFile.ignore();

                // skips the review if it exists
                getline(myFile, line);

                if (line != "")
                {
                    getline(myFile, line);
                    myFile.ignore();
                }

                tempCount++;
            }

            // dynamically allocates array to number of movies within file
            movies = new Movie *[tempCount];

            // resets the seeker
            myFile.clear();
            myFile.seekg(0, ios::beg); // https://www.geeksforgeeks.org/file-handling-c-classes/

            tempCount = 0;

            // second loops which reads the lines into the object
            while (!(myFile.eof()))
            {
                getline(myFile, rTitle);    // title
                getline(myFile, rDirector); // director
                myFile >> rYear;            // year
                myFile >> rRating;          // rating
                myFile.ignore();

                movies[tempCount] = new Movie(rTitle, rDirector, rYear, rRating);

                getline(myFile, reviewerName);

                if (reviewerName != "")
                {
                    getline(myFile, reviewText);
                    myFile.ignore();
                    movies[tempCount]->addReview(reviewerName, reviewText);
                }

                // counts the number of objects
                tempCount++;
            }

            myFile.close();

            cout << endl
                << fileName << " successfully loaded with " << tempCount << " movies.\n";

            numOfMovies = tempCount;
        }
        else
        {
            cout << "File failed to open." << endl;
        }
    }
    else
    {
        cout << endl << "There are already movies added or imported. Please try again when there are no movies added yet." << endl;
    }
};

void MovieLibrary::display()
{
    if (numOfMovies > 0)
    {
        for (int i = 0; i < numOfMovies; i++)
        {
            movies[i]->display();
        }
    }
    else
    {
        cout << endl
            << "There are no movies loaded. Please import or add first." << endl;
    }
}

void MovieLibrary::add()
{
    string rTitle;
    string rDirector;
    int rYear;
    float rRating;

    // create new array of pointers to movie objects with larger size
    Movie **newMovies = new Movie *[numOfMovies + 1];

    // copy the old movies to the new movies
    for (int i = 0; i < numOfMovies; i++)
    {
        newMovies[i] = movies[i];
    }

    // takes in user input
    cout << "\nTitle: ";
    cin.ignore();
    getline(cin, rTitle);
    cout << "\nDirector: ";
    getline(cin, rDirector);
    cout << "\nYear: ";
    cin >> rYear;
    cout << "\nRating: ";
    cin >> rRating;

    // adds new movie
    newMovies[numOfMovies] = new Movie(rTitle, rDirector, rYear, rRating);

    // Optionally, ask for a review:
    char reviewChoice;
    cout << "\nWould you like to add a review for this movie? (y/n): ";
    cin >> reviewChoice;
    if (tolower(reviewChoice) == 'y')
    {
        string reviewerName, reviewText;
        cout << "\nReviewer Name: ";
        cin.ignore();
        getline(cin, reviewerName);
        cout << "\nReview Text: ";
        getline(cin, reviewText);
        newMovies[numOfMovies]->addReview(reviewerName, reviewText);
    }

    // deletes old movies
    delete[] movies;

    // changes name of newMovies, back to movies
    movies = newMovies;

    numOfMovies++;
}

void MovieLibrary::save()
{
    ofstream outFile;
    string fileName;
    string target = ".txt";

    // checks if there are movies in loading
    if (numOfMovies > 0)
    {
        cin.ignore();

        cout << endl << "Type a file name (with '.txt') to create or overwrite: ";
        getline(cin, fileName);

        outFile.open(fileName, ios::out);
        if (outFile.is_open())
        {
            for (int i = 0; i < numOfMovies; i++)
            {
                movies[i]->save(outFile);
                if (i < numOfMovies - 1)
                    outFile << endl;
            }
        }
        else
        {
            cout << "Failed to open file." << endl;
        }
    }
    else 
    {
        cout << endl << "There are no movies to save. Please add or import movies then try to save again." << endl;
    }

}