/*                                  ———OLD CODE, IGNORE———
#include "movie.h"
#include <fstream>
#include "movieLibrary.h"
#include "C:\Users\brown\OneDrive\Documents\! School\CSC1310\Programs\Program-1---You-Got-It (09-30)"
namespace std;

// using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySolution

TEST_CLASS(UnitTest1)
{
public:
    TEST_METHOD(TestClassInit)
    {
        string name = "Movie";
        MyClass mc(name);
        Assert::AreEqual(name, mc.GetName());
    }
}

*/ 

/* "Ngl, I had NO idea how to do Test Case, had to use https://learn.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022 for assistance." —Shane */
#include <iostream>
#include <cassert>
#include <fstream>
#include "movie.h"
#include "movieLibrary.h"

using namespace std;

// for adding a movie to the library
void testAddMovie() {
    MovieLibrary myLibrary;

    
    cout << "Testing Add Movie..." << endl;
    myLibrary.add(); // requires manual input

    assert(myLibrary.findMovie("Test Movie") != nullptr); // validate movie's output

    cout << "Add Movie Test Passed!" << endl;
}

// test importing from a file
void testImportMovies() {
    MovieLibrary myLibrary;

    // test importing from a valid file
    cout << "Testing Import Movie..." << endl;
    myLibrary.import("data1.txt");  

    assert(myLibrary.findMovie("Oppenheimer") != nullptr); // validate movie exists after import
    assert(myLibrary.findMovie("Barbie") != nullptr);

    cout << "Import Movie Test Passed!" << endl;
}

// test displaying movies in the library
void testDisplayMovies() {
    MovieLibrary myLibrary;

    // manually add a movie to test display
    myLibrary.add();  // sample movie (for testing)

    cout << "Testing Display Movie..." << endl;
    myLibrary.display();

    cout << "Display Movie Test Passed!" << endl;
}

// test saving movies
void testSaveMovies() {
    MovieLibrary myLibrary;

    // to add more movies
    myLibrary.add();

    // test saving the movies to a file
    cout << "Testing Save Movie..." << endl;
    myLibrary.save("output.txt");

    ifstream inFile("output.txt");
    assert(inFile.good()); // validate file creation

    cout << "Save Movie Test Passed!" << endl;
}

int main() { // run the test cases
    testAddMovie();
    testImportMovies();
    testDisplayMovies();
    testSaveMovies();

    cout << "All test cases passed successfully!" << endl;

    return 0;
}
