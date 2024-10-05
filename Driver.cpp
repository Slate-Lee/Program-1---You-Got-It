/*
    Driver.cpp
    Has the main function, which has the menu and calls various functions.
*/

#include <iostream>
#include "movie.h"
#include "movieLibrary.h"

int main()
{

    // Creates library
    MovieLibrary myLibrary;

    // Movie choice variable
    int choice;

    // File name variable for import case
    string fileName;

    do
    {
        // menu options
        cout << "\n1 - Import";
        cout << "\n2 - Add";
        cout << "\n3 - Print";
        cout << "\n4 - Save";
        cout << "\n5 - Exit";

        do
        {
            cout << "\nCHOOSE: 1-5: ";
            cin >> choice;
            if (choice < 1 || choice > 5) {
                cout << endl << "Invalid choice." << endl;
            }

        } while (choice < 1 || choice > 5);

        switch (choice)
        {
        case 1:
            myLibrary.import();
            break;
        case 2:
            myLibrary.add();
            break;
        case 3:
            myLibrary.display();
            break;
        case 4:
            myLibrary.save();
            break;
        }
    } while (choice != 5);

    cout << endl << "Bye!" << endl;

    return 0;
}