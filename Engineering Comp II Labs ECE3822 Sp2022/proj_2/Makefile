CXX=g++
CXXFLAGS=-std=c++11

movie.o: movie.cpp movie.h
	$(CXX) $(CXXFLAGS) -c movie.cpp -o movie.o

customer.o: customer.cpp customer.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o

database.o: database.cpp database.h
	$(CXX) $(CXXFLAGS) -c database.cpp -o database.o

proj_2.o: proj_2.cpp
	$(CXX) $(CXXFLAGS) -c proj_2.cpp -o proj_2.o

all: movie.o customer.o database.o proj_2.o
	$(CXX) $(CXXFLAGS) movie.o customer.o database.o proj_2.o -o proj_2

debug:movie.o customer.o database.o proj_2.o
	$(CXX) $(CXXFLAGS) -g movie.o customer.o database.o proj_2.o -o debug

clean:
	rm -f *.o proj_2
