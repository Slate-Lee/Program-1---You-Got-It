/*
Project: Program 1 - Driver File
Names: David Slate Lee, Travis Mehaffy, Shane Brown
*/

#include "movie.h"
#include "movie.cpp"

int main () {

    int choice;

    // a pointer to an array of pointers to move objects

    do {
        cout << "\n1 - Load";
        cout << "\n2 - Add Movies";
        cout << "\n3 - Remove Movies";
        cout << "\n4 - Display";
        cout << "\n5 - Save And Exit";
        cout << "\nCHOOSE 1-5: ";
        cin >> choice;

        // Input validation
        while (choice < 1 || choice > 5)
        {
            cout << "INVALID. CHOOSE 1-5: ";
            cin >> choice;
        }

        // choices
        switch(choice)
        {
            case 1:
                break;
            case 2:

                string tTitle, tDirector;
                int tYear;
                double tRating;
                
                cin.ignore();

                cout << "\nTitle: ";
                getline(cin, tTitle);
                
                cout << "\nDirector: ";
                getline(cin, tDirector);
                
                cout << "\nYear: ";
                cin >> tYear;

                cout << "\nRating: ";
                cin >> tRating;
                
                Movie* myMovie = new Movie(tTitle, tDirector, tYear, tRating); 

                break;
            case 3:
                break;
            case 4:
                printMovies();
                break;
            case 5:
                break;
        }
    
    } while (choice != 5);

    return 0;
}