So far we've looked at two implementations for graphs: the fancy object-oriented one and the simple 2D matrix. 
In this project, we'll try a third implementation. I would recommend spending a little time thinking about 
the pros and cons of each approach.

Let's try the following implementation of a graph to capture a social network. Each member of
the network has a name and a list of friends. That list of friends must be stored in a linked list (not a
vector). I think the most straightforward approach would be for that linked list to just contain pointers
to the other members. You can use whatever classes or data types that make sense to you subject to the
following requirements:

    [0] Connections in this social network are bi-directional. So if Tom is friends with Harry, then Harry
    is also friends with Tom.

    [1] If you use a linked list, hash table, binary tree, or heap, you must use the library definitions
    that I've stored in $SHARE/include. You can make new classes that inherit those classes but you cannot
    "reinvent the wheel" by coding a linked list (or whatever) from scratch.

    [2] Your graph must support the following methods:
        void new_member(name)
        void new_connection(name1,name2)
        bool are_friends(name1,name2)
        int distance(name1,name2) [optional, but lots of fun]
    
    The distance function returns the shortest distance between two people. So if Tom and Harry are friends,
    they have a distance of 1. If Harry is friends with Richard, then Tom and Richard are at distance 2 from
    each other. If there is no connection, return -1.

Finally: and this is important

    [3] Write one or more testcases that demonstrate that your code works under as many conditions as
    possible. I am not providing you with test cases! Part of this assignment is for you to think up
    your own test cases that ensure the code works as robustly as possible under as many conditions as
    possible.

    If some function cannot complete it's task, it should print a helpful error message and
    exit gracefully. In other words, I should not be able to write a testcase of my own that causes
    something ugly like a segfault or an infinte loop. You should think about as many of these so-called
    "edge cases" as you can and prove that you can handle them cleanly.
