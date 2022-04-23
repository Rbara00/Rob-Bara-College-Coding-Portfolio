CXX=g++
CXXFLAGS=-std=c++11
INCL=-I$(SHARE)/include

all: lab_11.cpp
	$(CXX) $(CXXFLAGS) $(INCL) $< -o lab_11

clean:
	@rm -f *.o
	@find . -type f -executable -not -name "submit.py" -exec rm {} \;
