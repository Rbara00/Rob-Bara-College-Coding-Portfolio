You are given code for placing data in a binary search tree, nearly identical to what
we've been working on in class. Your job is to write the "delete_node" function. This 
function will accept as input a pointer to a node in a binary tree. You should delete 
that node and figure out how to handle its children. There are multiple ways to make 
this work. You should only edit the delete_node function.

I have written a "check_tree()" function that will determine whether the tree is still
"valid" after deleting a node. Remember that in a valid tree, smaller children go to the
left and larger ones to the right. Your "delete_node" function should leave behind
a valid tree.

I strongly suggest that you plan this out on paper before jumping in to the code.