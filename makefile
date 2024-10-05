movie: movietest.o review.o driver.o movie.o movieLibrary.o
    g++ movietest.o review.o driver.o movie.o movieLibrary.o -o movie

movietest.o: movietest.cpp
    g++ -c movietest.cpp

review.o: review.cpp
    g++ -c review.cpp

driver.o: driver.cpp
    g++ -c driver.cpp

movie.o: movie.cpp
    g++ -c movie.cpp

movieLibrary.o: movieLibrary.cpp
    g++ -c movieLibrary.cpp
    
clean:
    rm *.o movie