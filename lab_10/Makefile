CXX=g++
CXXFLAGS=-std=c++11


lab_10: lab_10.cpp
	$(CXX) $(CXXFLAGS) -o lab_10 lab_10.cpp


all: lab_10

clean:
	@find . -type f -executable -not -iname "submit.py" -exec rm {} \;
	@rm -f *.o
