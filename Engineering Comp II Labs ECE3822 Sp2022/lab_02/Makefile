CXX=g++
CXXFLAGS=-std=c++11

circularBuffer.o: circularBuffer.cpp  circularBuffer.h 
	$(CXX) $(CXXFLAGS) -c circularBuffer.cpp

lab_02.o: lab_02.cpp 
	$(CXX) $(CXXFLAGS) -c lab_02.cpp	

all: lab_02.o  circularBuffer.o
	$(CXX) $(CXXFLAGS) circularBuffer.o lab_02.o -o lab_02 

clean:
	rm -rf *.o
	find . -type f -executable -exec rm -rf {} \;