CXX=g++
CXXFLAGS=-std=c++11

card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c card.cpp

cards.o: cards.cpp cards.h card.o
	$(CXX) $(CXXFLAGS) -c cards.cpp

testcases.o: testcases.cpp testcases.h
	$(CXX) $(CXXFLAGS) -c testcases.cpp

proj_1.o: proj_1.cpp testcases.o card.o cards.o 
	$(CXX) $(CXXFLAGS) -c proj_1.cpp

proj_1: proj_1.o testcases.o card.o cards.o
	$(CXX) $(CXXFLAGS) proj_1.o testcases.o card.o cards.o -o proj_1

all: cards.o card.o testcases.o proj_1.o
	$(CXX) $(CXXFLAGS) cards.o card.o testcases.o proj_1.o -o proj_1


clean:
	rm -f *.o proj_1
