CXX=g++
CXXFLAGS=-std=c++11

all: lab_07

lab_07: lab_07.cpp
	$(CXX) $(CXXFLAGS) lab_07.cpp -o lab_07
debug:
	$(CXX) $(CXXFLAGS) -g lab_07.cpp -o debugger

clean:
	@find . -type f -executable -not -name "submit.py" -exec rm {} \;

