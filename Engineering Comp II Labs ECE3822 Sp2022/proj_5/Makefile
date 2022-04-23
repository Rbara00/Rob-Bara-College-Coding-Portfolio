CXX=g++
CXXFLAGS=-std=c++11
INCL=-I$(SHARE)/include

# you might want to edit this
all: proj_5.cpp
	$(CXX) $(CXXFLAGS) $(INCL) $< -o proj_5

debug: proj_5.cpp
	$(CXX) -g $(CXXFLAGS) $(INCL) $< -o debug

clean:
	@rm -f *.o
	@find . -type f -executable -not -name "submit.py" -exec rm -f {} \;
