**Goal:** 
The goal of Project 2 is to design a data structure to hold some information that is stored 
in a text file. Your data structure must be able to hold the data and perform various tasks with it.

**Acquire Code:**

rsync -rv $SHARE/proj_2 .

**Data: **
You work for an online video streaming service, and you have to manage data on your customers. Each 
customer has an ID number and a list of movies they watched last month. The data is stored in a text 
file in the following format:
    customer ID number
    number of movies watched last month
    ID numbers of the movies watched last month

For example: suppose a file has data on two customers, it might look like this:

724
3
225
502
109
449
2
109
305

Customer #1 has ID number 724 and watched 3 movies whose ID numbers are 225, 502, and 109.
Customer #2 has ID number 449 and watched 2 movies whose ID numbers are 109 and 305

As you can see, both customers watched the movie whose ID number is 109

**What do Do:**
Write a C++ program that reads customer information from the text files provided below and stores the 
data in a data structure (or structures) of your choosing.

Your code should have the following functions:

print_all - prints all the customer information in this format:

Customer 724 watched 225, 502, 109
Customer 449 watched 109, 305

print_customer(customerID) - prints the information for a specific customer

Customer 724 watched 225, 502, 109

print_views(movieID) - prints the number of customers who watched a movie

Movie 109 was watched 2 time(s)

**What/Where to Code:**

Do not edit proj_2.cpp

Feel free to edit the database class. You may also add other classes if you think that would help.

**How to Run:**

./proj2 data_file_num test_file_num optional_id_num

So if you're running testcase 1 on dataset 1 you would type

./proj2 1 1

But if you were running testcase 3 on database 2 and you wanted to query movie 471 you would type

./proj2 2 3 471

**Grading:**

    15 points for designing a data structure(s) that make(s) sense
    15 points for correctly coding the data structure(s)
    5 points for print_all
    5 points for print_customer
    5 points for print_views
    5 points for good coding style and presentation

**Data Files:**
There are three data files for you to test your algorithm, the first one is pretty short, the last one 
is pretty long.

dataFile1.txt  
dataFile2.txt
dataFile3.txt 