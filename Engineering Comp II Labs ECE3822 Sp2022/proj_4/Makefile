CXX=g++
CXXFLAGS=-std=c++11

all: proj_4

proj_4: proj_4.cpp hash_table.h bst.h
	$(CXX) $(CXXFLAGS) proj_4.cpp -o proj_4

debug: hash_table.h 
	$(CXX) $(CXXFLAGS) -g proj_4.cpp -o proj_4

clean:
	@find . -type f -executable -not -name "submit.py" -exec rm {} \;
	@rm -f *.o
