LL_Node: LL_Node.cpp LL_Node.h
	g++ -c LL_Node.cpp
	
LL: LL.cpp LL.h
	g++ -c LL.cpp

Tree_Node: Tree_Node.cpp Tree_Node.h
	g++ -c Tree_Node.cpp

lab_08: lab_08.cpp
	g++ -c lab_08.cpp
	
all: LL_Node.o LL.o Tree_Node.o lab_08.o
	g++ lab_08.o LL_Node.o LL.o Tree_Node.o -o lab_08.exe

clean:
	rm -f *.o *.exe