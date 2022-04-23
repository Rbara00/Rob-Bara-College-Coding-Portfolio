'''
lab_03.py

   Rob Bara
   tuj22026
   2/02/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This file contains a class and driver for a circular buffer
   the driver function simply loads the buffer with 4 elements
   counting down from 10, and prints the buffer
   
   Usage: 
   Running:
   python3 lab_03.py
'''

# this is a class definition for a circular buffer.
# there is no distinction in Python between public
# and private class variables. Member variables
# and functions must be prepended with "self."
# see code below for examples

class circular_buffer:

    # constructor - allocate and clear memory
    def __init__(self,buffer_size):

        # capture and store the buffer size
        self.buffer_size = buffer_size

        # place "buffer_size" zeros in the array
        self.buffer = []
        for i in range(buffer_size):
            self.buffer.append(0)

        # set the current index to zero
        self.curr_index = 0


    # print the contents of the buffer
    def print_buffer(self):
        for b in self.buffer:
            print(b)


    # insert a new value into the buffer, overwriting the oldest value
    def insert(self,new_val):
        # WRITE TWO LINES OF CODE HERE
        # TO DO THE INSERT FUNCTION
        self.buffer.pop(0)
        self.buffer.append(new_val)

def main():

    # create an instance of a circular buffer
    my_buffer = circular_buffer(buffer_size=4)

    # store the numbers 0-9 in that buffer, remembering
    # that the buffer will only keep track of the most
    # recent "buffer_size" values
    for i in range(10):
        my_buffer.insert(i)

    # print the contents of the buffer to confirm it works
    # as expected
    my_buffer.print_buffer()
    

if __name__=="__main__":
    main()