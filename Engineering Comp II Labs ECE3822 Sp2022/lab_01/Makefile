student.o: student.cpp student.h 
	g++ -std=c++11 -c student.cpp

lab_01.o: lab_01.cpp 
	g++ -std=c++11 -c lab_01.cpp

lab_01: student.o lab_01.o
	g++ -std=c++11 student.o lab_01.o -o lab_01

clean:
	rm -rf *.o
	find . -type f -executable -exec rm -rf {} \;
