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
        cout << "\n1 - Import";
        cout << "\n2 - Add";
        cout << "\n3 - Print";
        cout << "\n4 - Save";
        cout << "\n5 - Exit";

        do
        {
            cout << "\nCHOOSE: 1-5: ";
            cin >> choice;
        } while (choice < 1 || choice > 5);

        switch (choice)
        {
        case 1:
            cout << "\nType name of file to import: ";
            cin.ignore();
            getline(cin, fileName);
            myLibrary.import(fileName);
            break;
        case 2:
            myLibrary.add();
            break;
        case 3:
            myLibrary.display();
            break;
        case 4:
            cout << "\nType name of file to create or overwrite: ";
            cin >> fileName;
            myLibrary.save(fileName);
            break;
        }
    } while (choice != 5);

    return 0;
}