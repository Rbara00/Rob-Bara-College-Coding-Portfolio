'''
lab_04.py

   Rob Bara
   tuj22026@temple.edu
   2/09/2022
   
   Description: File proposes a simple node and linkedlist class which allows for the user in the main
   program to clear the list, insert to the front of the linked list, pop a value from the front of the linked list, 
   as well as print the value stored in the node, check if the list is empty, or check the length of the linked list

   Usage:
   python3 lab_04.py
'''

class node:
    def __init__(self,val=None):
        self.val = val
        self.next = None
    def getNext(self):
        return self.next
    def getVal(self):
        return self.val
        
class linkedList:
    
    def __init__(self):
        # constructor
        self.head = None
        self.length=0   #keeps track of how many elements are in the linked list
        
    def insert(self,val):
        # insert at the front of the list
        newNode = node(val)
        newNode.next = self.head
        self.head = newNode
        self.length+=1  #increment the counter of the number of elements in the linked list

    def pop(self):
        # pop (remove) from the front of the list
        # if list isn't empty, remove the front item from the linked
        # list and return it

        # PRIORITY LOGIC: if the list is empty, just return None
        if(self.isEmpty is True):
            return None
        currNode=self.head          #define a node and set equal to the head of list
        while currNode is not None:
           poppedVal=currNode.val   #Pop the value stored from the head
           self.head=currNode.next  #Set the head to the next node
           self.length-=1           #decrement the counter of the number of elements in the linked list
           return poppedVal         # return the Popped Value

    def len(self):
        # returns the current length of the linkedList
        return self.length

    def isEmpty(self):
        # return True if the list is empty and False otherwise
        if(self.length == 0):
            return True 
        else:
            return False

    def clearList(self):
        # clears the list
        while self.len() is not 0:
            self.pop()  #Pop all the values off the list until the list is empty

    def printList(self):
        # print list in order of newest-added
        # to oldest-added
        currNode = self.head
        while currNode is not None:
            print(currNode.val)
            currNode = currNode.next

        
def printStatus(myList):
    # DON'T CHANGE THIS
    statement_1 = "the list is empty"
    statement_2 = "the list is not empty"
    
    print("The list has" , myList.len() , "elements")
    print(statement_1 if myList.isEmpty() else statement_2)
    print("\n")

    
def main():
    # DON'T CHANGE ANYTHING HERE IN MAIN

    myList = linkedList()

    # list should be empty
    printStatus(myList)
    
    myList.insert(8)
    myList.insert(6)
    myList.insert(7)
    myList.insert(5)
    myList.insert(0)

    # list should contain five items
    printStatus(myList)

    # remove two items from list    
    print("popping " , myList.pop() )
    print("popping " , myList.pop() )

    # list should contain three items
    printStatus(myList)

    # pop from list, including from an empty list
    print("popping " , myList.pop() )
    print("popping " , myList.pop() )
    print("popping " , myList.pop() )
    print("popping " , myList.pop() )
    print("popping " , myList.pop() )
    
    # list should be empty
    printStatus(myList)

    # place two items in the list
    myList.insert(12)
    myList.insert(-2)
    
    # clear the list
    myList.clearList()

    # demonstrate the list was properly cleared
    printStatus(myList)

if __name__=="__main__":
    # DON'T CHANGE THIS
    main()
