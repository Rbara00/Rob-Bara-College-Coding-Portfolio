''' lab_05.py

   Rob Bara
   tuj22026@temple.edu
   2/14/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This file implements a doubly linked list within python and allows for functions
   such as inserting to the front of the list, printing all elements, and printing an
   n'th element from the back of the list.

   Usage:
   python lab_05.py

'''

class node:
    def __init__(self,_data):
        self.data = _data
        self.next = None
        self.prev = None

# define the LINKEDLIST class
class linkedList:

    # constructor - init the class vars
    def __init__(self):
        self.head = None
        self.tail = None
        self.n_elements = 0

    # insert a new element in the list
    def insert(self,new_val):
        # Step 0: Create a node to store the new value to be inserted
        # Set the pointer to the next node to be the head, thus pushing the nodes up an index
        # with the next pointer being the start
        new_node = node(new_val)     
        new_node.next = self.head    
        
        #Priority Logic:
        #case 1: if the list is empty, then create the head and tail of the list, so the list has
        #        a start and stop. This means that we have set both directions to be a new node 
        #        that we can add to, however since there is no values yet, they point to the same value
        if self.n_elements == 0:
            self.head = new_node
            self.tail = new_node
        
        #case 2: When the list is not empty, store the previous value to the previous head pointer 
        #        and set the head to a new node containting the new inserted value, therefore inserting 
        #        the node to the front of the linked list, while pushing the previous head back an index 
        #        the node with the passed in value
        else:
            self.head.prev = new_node    
            self.head = new_node    

        #Increment the counter for the number of elements so we know the length of the list
        self.n_elements += 1         
        
    # print the entire list, front to back
    def print_all(self):
        curr = self.head
        if curr is None:
            print("list is empty")

        else:
            while (curr.next is not None):
                print(curr.data, "-->" , end=" ")
                curr = curr.next
            print(curr.data)

    def print_nth_element_from_back(self,n):
        # This function prints the nth element from the back of the linked list
        # you can assume n is a positive integer
        
        # step 0: set the pointer to the end of the linked list
        #        set the previous pointer to the node right before the tail
        #Calculate the length for iteration through the list starting at i=0 
        curr=self.tail
        curr.prev=self.tail.prev
        len=self.n_elements-1   

        #Priority Logic
        # Case 1: if n=0, no need to update the pointer, it points to the last item in the list
        if n == 0:
            print(curr.data)    #print the last item in the list

        # Case 2: if the value of n is longer than the list itself and
        # there is no item to print, then just print 'none'
        if (n > self.n_elements):
            print(None)

        # Case 3: if n is in the range of the linked list
        # for example, if n=1, then print the second to last item in the list
        if n >= 1 and n<self.n_elements:
            #step 1: loop as long as there are elements in the linked list
            for i in range(len):
                # Step 2: Update the pointers upon each loop
                curr=curr.prev      #set the current pointer to the previous node
                curr.next=curr.prev #set the next pointer to be the previous pointer
                if i==(len-n) :     
                    # Step 3: When i is equal to the length of the list minus n, then
                    # the correct position is reached. For example if the length is 4,
                    # n is 2, then the nth element from the back is equal to the 1st element
                    # from the front. length=4, with range 0 to 3, 3-2=1st node 
                    print(curr.data)


def main():

    myList = linkedList()
    myList.insert(9)
    myList.insert(4)
    myList.insert(-8)
    myList.insert(12)

    print("")

    print( "printing full list: ", end="" )
    myList.print_all()

    print("")

    print( "the 0th element from the back is: ", end="" )
    myList.print_nth_element_from_back(0)

    print( "the 2nd element from the back is: ", end="" )
    myList.print_nth_element_from_back(2)

    print( "the 4th element from the back is: ", end="" )
    myList.print_nth_element_from_back(4)

    print("")

if __name__ == "__main__":
    main()
