I have written C++ code that creates and populates a special data structure which 
looks like this: Imagine we have a binary tree. In addition to the left and right 
pointers, each node of the binary tree has an integer key, AND a pointer to a linked 
list. Your task is simple: print all the data (keys and linked lists) by calling the 
single command that you see on line 40 of lab_08.cpp: "n0.printTree();"

You will need to declare and write the printTree() function. You will notice that I 
have already written functions to print an individual node, so MOST of the work is 
already done for you. There is no need to edit the existing print functions. You can 
just call those function(s) as needed from printTree().

Note that there are many files: 3 header files and 4 cpp files, plus a Makefile. Part 
of the challenge will be figuring out where to write your code. The actual code you're 
writing is fairly short (my solution is about 4 lines). The order in which the nodes are 
printed doesn't matter. You shouldn't have to make any changes at all to lab_08.cpp.

My solution looks like this. Your might look different ... remember node order doesn't
matter:

0: 97 -> 92 -> 85
1: 61 -> 65
3: 55
4: 27 -> 66
2: 
5: 39 -> 67 -> 87
6: 76

Good luck!