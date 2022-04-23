################################
## 
## Lab 00
## Robert Bara
## 1/12/2022
##
## This python program takes in 1000 random integers that was given by a file and calculates the average by
## reading the data into an array and using the python's sum() and len() methods.
##
################################

# step 1: load data from file into array:
# do not edit this section
x = []
with open("lab_00_data.txt") as f:
    for line in f:
        x.append(int(line))

# step 2: Compute the average of the values in x and store it in a variable named avg
# First find the sum of all elements stored in array x using the sum function
# Then find the total number of elements stored in array x using the len function
avg = sum(x)/len(x)    #Computing the average=SUM/total Number of Elements
# step 3: print the value:
print("The average value is " , avg)
