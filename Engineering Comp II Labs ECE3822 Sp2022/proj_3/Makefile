CXX=g++
CXXFLAGS=-std=c++11

student: student.cpp student.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student

queue: queue.cpp queue.h
	$(CXX) $(CXXFLAGS) -c queue.cpp -o queue

all: proj_3.cpp student.o queue.o
	$(CXX) $(CXXFLAGS) -pthread proj_3.cpp student.o queue.o -o proj_3

debug: 
	$(CXX) $(CXXFLAGS) -g -pthread proj_3.cpp student.cpp queue.cpp -o proj_3	

clean:
	@find . -type f -executable -not -name "submit.py" -exec rm {} \;
	@rm -f *.o
