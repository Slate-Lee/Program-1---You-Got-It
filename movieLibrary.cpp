#include "movieLibrary.h"
#include <fstream>

MovieLibrary::MovieLibrary()
{
    movies = nullptr;
    numOfMovies = 0;
};

// TODO DEFINE DESTRUCTOR
MovieLibrary::~MovieLibrary()
{
    for (int i = 0; i < numOfMovies; i++)
    {
        delete movies[i];
    }
    delete movies;  
};

void MovieLibrary::import(string fileName)
{
    // definitions
    ifstream myFile;
    string line;

    string rTitle;
    string rDirector;
    int rYear;
    float rRating;

    int tempCount = 0;

    // opens file
    myFile.open(fileName, ios::in);
    if (myFile.is_open())
    {
        // first loop which counts the number of lines
        while (!myFile.eof())
        {
            getline(myFile, line); // title
            getline(myFile, line); // director
            myFile >> rYear;       // year
            myFile >> rRating;     // rating
            myFile.ignore();

            tempCount++;
        }

        // dynamically allocates array to number of movies within file
        movies = new Movie *[tempCount];

        // resets the seeker
        myFile.clear();
        myFile.seekg(0, ios::beg); // https://www.geeksforgeeks.org/file-handling-c-classes/
        tempCount = 0;

        // second loops which reads the lines into the object
        while (!myFile.eof())
        {
            getline(myFile, line); // title
            rTitle = line;
            getline(myFile, line); // director
            rDirector = line;
            myFile >> rYear;   // year
            myFile >> rRating; // rating
            myFile.ignore();

            // creates new movie object
            movies[tempCount] = new Movie(rTitle, rDirector, rYear, rRating);

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
        cout << "file failed to open";
    }
};

void MovieLibrary::display()
{
    for (int i = 0; i < numOfMovies; i++)
    {
        movies[i]->display();
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

    // deletes old movies
    delete[] movies;

    // changes name of newMovies, back to movies
    movies = newMovies;

    numOfMovies++;
}

void MovieLibrary::save(string fileName)
{
    ofstream outFile;

    outFile.open(fileName, ios::out);
	if (outFile.is_open())
	{
        for (int i = 0; i < numOfMovies; i++)
        {
            movies[i]->save(outFile);
            if (i < numOfMovies-1)
                outFile << endl;
        }
    }
    else
    {
        cout << "failed to open file";
    }
}