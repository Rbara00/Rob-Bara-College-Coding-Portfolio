CXX=g++
CXXFLAGS=-std=c++11

timing_example: timing_example.cpp
	$(CXX) $(CXXFLAGS) timing_example.cpp -o timing_example

bubble.o: bubble.cpp bubble.h	
	$(CXX) $(CXXFLAGS) -c bubble.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

RNG.o: RNG.cpp RNG.h
	$(CXX) $(CXXFLAGS) -c RNG.cpp

merge.o: merge.cpp merge.h
	$(CXX) $(CXXFLAGS) -c merge.cpp

lab_09.o: lab_09.cpp
	$(CXX) $(CXXFLAGS) -c lab_09.cpp

lab_09: lab_09.o bubble.o heap.o RNG.o merge.o
	$(CXX) $(CXXFLAGS) lab_09.o heap.o bubble.o merge.o RNG.o -o lab_09

all:
	make lab_09
	make timing_example

clean:
	@find . -type f -executable -exec rm {} \;
	@rm -f *.o
