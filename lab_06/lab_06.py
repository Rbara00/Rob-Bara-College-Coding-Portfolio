''' lab_06.cpp
    03/02/2022
    Rob Bara
    Tuj22026@temple.edu
   
   BRIEF DESCRIPTION OF FILE CONTENTS:
    This Python file is an implementation of a binary search tree, which is a data structure
    that will insert a node either to the left or to the right of the previous inserted value,
    based upon if the value is greater than or less than the previous value.

    One way of determining if a tree is well balanced is to count how many of the nodes
    have zero children, one child, or two children. Well-balanced trees will have very few
    nodes with just one child. A degenerate tree will have all nodes with one child, except the
    very last node which will have zero children. The count() function determines how many nodes
    with zero, one, or two children are there. 
    
    This is tested through the driver program at the end of this file with 3 testcases. The third 
    case reads 1000 randomly generated ints out of a file and places them into a tree. From the this
    the count function will return:
        Nodes with 0 children: 345
        Nodes with 1 children: 311
        Nodes with 2 children: 344

   Usage:
    python3 lab_06.py (arg 0, 1, or 2),
    example: to run testcase 0
             python3 lab_06.py 0
'''

from itertools import count
import sys
from turtle import right

class node:

    def __init__(self,val):
        self.payload = val
        self.left  = None
        self.right = None
    
    def set_left(self, ptr):
        self.left = ptr
    
    def set_right(self,ptr):
       self.right = ptr

    def get_val(self):      return self.payload
    def get_left(self):     return self.left
    def get_right(self):    return self.right
    

class tree:

    def __init__(self):
        self.root = None
        self.cnt_0 , self.cnt_1 , self.cnt_2 = 0 , 0 , 0
    
    def insert(self,val):
        new_node = node(val)
        curr_node = self.root

        if curr_node is None:
            self.root = new_node
            return
        
        while True:
            
            if val < curr_node.get_val():
                if curr_node.get_left() is None:
                    curr_node.set_left(new_node)
                    return
                else:
                    curr_node = curr_node.get_left()
            else:
                if curr_node.get_right() is None:
                    curr_node.set_right(new_node)
                    return
                else:
                    curr_node = curr_node.get_right()

    def count(self,curr_node = None):
        #This function counts how many nodes have zero, one, or two child nodes
        #and stores the result in counters that are member vars of the tree class

        if (curr_node == None):
            # if count is called without an input var, curr_node will be None
            # which means count is being called directly from testcase (not recursively).
            # in this case, init curr_node to root and set the count values = 0
            curr_node = self.root
            self.cnt_0 , self.cnt_1 , self.cnt_2 = 0 , 0 , 0

        if(curr_node!=None):
            # if count is called with an input var, check for left and right nodes
            left_node=curr_node.get_left()
            right_node=curr_node.get_right()

            #reached the last node when there are no nodes to the left or right
            if((left_node is None) and (right_node is None)): 
                self.cnt_0+=1   #increase 0 counter
           #reached one of the child nodes if there is a left or right node
            elif((left_node is None) and (right_node is not None)): 
                self.cnt_1+=1   #increase 1 counter
            elif((left_node is not None) and (right_node is None)): 
                self.cnt_1+=1   #increase 1 counter
            #both child nodes exist if there are left and right nodes avaliable
            elif((left_node or right_node) is not None): 
                self.cnt_2+=1   #increase 2 counter
            
            #recurse the function for the left and right nodes
            if(left_node is not None): self.count(left_node)
            if(right_node is not None): self.count(right_node)

        #return counters for 0, 1, and 2 children
        return self.cnt_0,self.cnt_1,self.cnt_2    

    def print_count(self):
        print("Nodes with 0 children: " , self.cnt_0)
        print("Nodes with 1 children: " , self.cnt_1)
        print("Nodes with 2 children: " , self.cnt_2)
        print("")


def testcase_0():
    print("\nTestcase 0")
    print("---------------")
    x = tree()
    x.insert(8)         #8              num of nodes w 2 children=1
    x.insert(6)       #7  #9                         w 1 child   =1
    x.insert(7)      #6                              w 0 children=2
    x.insert(9)
    x.count()
    x.print_count()

def testcase_1():
    print("\nTestcase 1")
    print("---------------")
    x = tree()
    x.insert(9)       #9                num of nodes w 2 children=0
    x.insert(8)     #8                  num of nodes w 1 child   =3
    x.insert(7)    #7                   num of nodes w 0 child   =1
    x.insert(6)   #6                     
    x.count()
    x.print_count()

def testcase_2():
    print("\nTestcase 2")
    print("---------------")
    x = tree()

    with open("data.txt") as f:
        for str in f.readlines():
            x.insert( int(str) )

    x.count()
    x.print_count()


def main(argv):

    if (len(argv) != 1) or not ( 0 <= int(argv[0]) <= 2 ):
        print("command line arguments must be 0, 1, or 2")
        exit(1)

    opt = int(argv[0])
    if opt == 0: testcase_0()
    if opt == 1: testcase_1()
    if opt == 2: testcase_2()
    

if __name__ == "__main__":
    main(sys.argv[1:])
