#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

/* lab_07.cpp

   Robert Bara
   tuj22026@temple.edu
   03/07/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This program is an implementation of a binary search tree. The program consists of two classes
   a node class and a binary search tree class. Finally a driver program is included to test
   the classes

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make all
    Run:    ./lab_07
*/

//****************************************************************************
// NODE CLASS                                                           
//      defines the "nodes" for the binary search tree

class node{
    private:

    int data;
    node* left;
    node* right;

    public:

    node(int d){
        set_data(d);
        set_left(NULL);
        set_right(NULL);
    }

    void set_data(int d){data = d;}
    int get_data(){return data;}

    void set_left(node* n){left = n;}
    node* get_left(){return left;}

    void set_right(node* n){right = n;}
    node* get_right(){return right;}

};

//****************************************************************************
// TREE CLASS                                                           
//      defines the binary search tree
//      methods include:
//          constructor
//          insert
//          find
//          print
//          count_nodes
//          check_tree
//          delete_node

class tree{

    private:
    node* root;
    int n_nodes;

    public:

    // constructor
    tree(){
        root = NULL;
        n_nodes = 0;
    }

    // insert value "d" into the tree
    void insert(int d){
        // DON'T EDIT THIS FUNCTION

        n_nodes += 1;

        node* p_new_node = new node(d);
        node* p_prev_node = NULL;
        node* p_curr_node = root;
        bool left = false;

        // if we have an empty tree, make the new node the root and exit
        if (root == NULL){
            root = p_new_node;
            return;
        }

        // else, traverse down the tree looking for the correct location
        // to put the new node
        while (p_curr_node != NULL){
            p_prev_node = p_curr_node;

            // if d is smaller than current node, branch left
            if (d < p_curr_node->get_data() ){
                p_curr_node = p_curr_node->get_left();
                left = true;
            }

            // otherwise branch right
            else{
                p_curr_node = p_curr_node->get_right();
                left = false;
            }
        }

        // once the correct parent has been located, 
        // connect up the new node and exit
        if (left)
            p_prev_node -> set_left(p_new_node);
        else
            p_prev_node -> set_right(p_new_node);

    }

    node* find(int target, node* p_curr_node=NULL){

        // DON'T EDIT THIS FUNCTION

        // return a pointer to a target piece of data.
        // if the data is found, return a pointer to the node
        // if the data is not found, return null.
        // the function works recursively

        if (p_curr_node==NULL)
            p_curr_node=root;

        node* tmp;

        // is this the data we're looking for?
        if (p_curr_node->get_data() == target)
            return p_curr_node;
        
        // if not, try recursing left
        if (p_curr_node->get_left()!=NULL){
            tmp = find(target,p_curr_node->get_left() );
            if (tmp != NULL)
                return tmp;
        }

        // also try recursing right
        if (p_curr_node->get_right()!=NULL){
            tmp = find(target,p_curr_node->get_right() );
            if (tmp != NULL);
                return tmp;
        }

        // return null only when you are sure no node below p_curr_node
        // contains the target value
        return NULL;
    }


    void print(node* p_curr_node = NULL, int level=0){

        // DON'T EDIT THIS FUNCTION
        
        // print the contents of the tree along with the "level" of each node
        // this function works recursively

        if (p_curr_node==NULL){
            p_curr_node = root;
            level = 0;
            cout << "\n<-------PRINTING TREE------->" << endl;
        }
        cout << "level " << level << "\t" << p_curr_node->get_data() << endl;;

        if (p_curr_node->get_left()!=NULL)
            print(p_curr_node->get_left() , level+1);
        if (p_curr_node->get_right()!=NULL)
            print(p_curr_node->get_right() , level+1);
    }

    int count_nodes(node* p_curr_node=NULL){
        
        // DON'T EDIT THIS FUNCTION

        // counts the number of nodes in the tree

        if (p_curr_node==NULL)
            p_curr_node = root;

        if (p_curr_node == NULL)
            return 0;
        
        int cnt_left = 0;
        int cnt_right = 0;

        if (p_curr_node->get_left() != NULL)
            cnt_left = count_nodes(p_curr_node->get_left());

        if (p_curr_node->get_right() != NULL)
            cnt_right = count_nodes(p_curr_node->get_right());

        return 1 + cnt_left + cnt_right;
    }

    bool check_tree(node* p_curr_node=NULL){
        
        // DON'T EDIT THIS FUNCTION
        
        // this checks to make sure the tree is valid

        if (p_curr_node==NULL)
            p_curr_node = root;
        
        bool left = true;
        bool right = true;

        if (p_curr_node->get_left()!=NULL)
            if (p_curr_node->get_left()->get_data() < p_curr_node->get_data() )
                left = check_tree(p_curr_node->get_left() );
            else
                return false;
        
        if (p_curr_node->get_right()!=NULL)
            if (p_curr_node->get_right()->get_data() > p_curr_node->get_data() )
                right = check_tree(p_curr_node->get_right() );
            else
                return false;

        return left & right & (count_nodes() == n_nodes);
        
    }

    //=================================================================================================================
    // I would like to point out, I think I am close, I've been using the debugger for most of this lab, however
    // testcase 3 is the only ones I can not fully figure out, for some reason I can not get the 20 in the left node 
    // pointed to, left of it. I know the issue lies in the switch statement case 2 within the deletenode function, line 363. 
    // Otherwise, though a little messy, it works.
    //=================================================================================================================
    //This function's purpose is to find the parent node
    node* findParent(int target_parent, node* p_curr_node=NULL){
        node* tmp; //temporary node pointer for recursing left or right if there are more children
        //Priority logic, if current node is null, then it is the start of the tree
        if(p_curr_node==NULL) p_curr_node=root;

        //if there is a child on the left
        if(p_curr_node->get_left()!=NULL){
            //check if the left child node's data matches the target data (the node worth deleting)
            if(p_curr_node->get_left()->get_data()==target_parent){
                return p_curr_node;       //the child matches the deleted node, so we found the parent
            }
            //If the data does not match, keep recursing left
            else{ 
                tmp=findParent(target_parent, p_curr_node->get_left());
                if(tmp!=NULL) return tmp;    //as long as temp is valid, return it
            }
        }

        //if there is a child on the right
        if(p_curr_node->get_right()!=NULL){
            //check if the right child node's data matches the target data (the node worth deleting)        
            if(p_curr_node->get_right()->get_data()==target_parent){
                return p_curr_node;     //the child matches the deleted node, so we found the parent
            }
            //If the data does not match, keep recursing right
            else{
                tmp=findParent(target_parent, p_curr_node->get_right());
                if(tmp!=NULL) return tmp;   //as long as temp is valid, return it
            }      
        }
        //for any other case return null
        else return NULL;
    }

    //This functions purpose is to count the number of children the parent node contains
    int count_children(node* p_parent_node){
        node* left=p_parent_node->get_left();//pointer to left node (for readability)
        node* right=p_parent_node->get_right();//pointer to right node
        //delcare the children count
        int children;
        //When both left and right nodes do not exist, then there are 0 children
        if((left && right==NULL)) children=0;
        //When only left or right nodes exist, then there is 1 child
        if((left!=NULL) && (right==NULL)){
            children=1;
            cout<<"1 Child. Left Child contains: "<<left->get_data()<<endl;
        } 
        if((left==NULL) && (right!=NULL)) {
            children=1;
            cout<<"1 Child. Right Child contains: "<<right->get_data()<<endl;
        }
        //When both left and right nodes exist, then there are 2 children
        if((left && right!=NULL)){ 
            children=2;
            cout<<"2 Children. Left: "<<left->get_data()<<" Right: "<<right->get_data()<<endl;
        }
        //return the number of children
        return children;
    }

    //This function deletes a node based on the pointer passed in
    void delete_node(node* p_to_delete){
        node* p_parent_node;
        int children, tmp1, tmp2, tmp3;
        //priority logic: if the pointer does not exist in tree, return (testcase 4)
        if(p_to_delete==NULL) return;

        //priority logic: if the pointer is the root of the tree, switch the data 
        // of the root and the left of  the root's data, then continue as normal (testcase 3)   
        if(p_to_delete==root) {
            tmp1=(root->get_left()->get_data()); //get left's data
            tmp2=root->get_data(); //save root's data
            tmp3=root->get_right()->get_data();//get right's data    
            root->set_data(tmp1);//set root as left data
            root->get_left()->set_data(tmp2); //update left as root's data (p to be deleted)
            root->get_right()->set_data(tmp3); //ensure the right node stays the same
            //since we switched the places of the root and left of root, update the pointer
            //of the node that needs to be deleted
            p_to_delete=root->get_left(); 
            p_parent_node=root; //set the parent node as the root
        }
        //Otherwise, locate the parent node of the node that will be deleted
        //do this by passing in the node to be deleted with the target data
        else{
            p_parent_node=findParent(p_to_delete->get_data());
        }

        cout<<"\n"<<p_parent_node->get_data()<<" is the parent"<<endl;
        //find the number of children of the desired node to be deleted
        children=count_children(p_to_delete);

        //Based on the number of children, perform a case
        switch(children){
            default: //case when there are 0 children (for testcase 1 node 11 uses this)
                //if the parent node is less than p_to_delete,
                if(p_parent_node->get_data()<p_to_delete->get_data())
                    p_parent_node->set_right(NULL); //right becomes null
                //otherwise
                else p_parent_node->set_left(NULL); //left becomes null
            break;
            case 1: //case when there is 1 child node (for testcases 0 and 1)
                //When the child is the left child
                if(p_to_delete->get_left()!=NULL){
                    //set the left node to be the next left node
                    p_parent_node->set_left(p_to_delete->get_left());
                    //if the parent node is greater than the deleted node's data, update the left to point to the left node
                    if(p_parent_node->get_data()>p_to_delete->get_data()){
                        p_parent_node->set_left(p_to_delete->get_left());
                    }
                }
                else{ //When the child is the right child
                    //set the left node to take on the right child
                    p_parent_node->set_left(p_to_delete->get_right());
                    //if the parent node is less than the deleted node's data, update the left to point to the right node
                    if(p_parent_node->get_data()<p_to_delete->get_data()){
                        p_parent_node->set_left(p_to_delete->get_right());
                    }
                }
            break;
            case 2: //case where there is 2 children (for testcases 2 and 3)
                    //set the left node to be the next left node
                    p_parent_node->set_left(p_to_delete->get_left());
                    //if the parent node is greater than the deleted node's data, update the left to point to the left node
                    if(p_parent_node->get_data()>p_to_delete->get_data()){
                        p_parent_node->set_left(p_to_delete->get_left());
                    }
                    
                    //When the child is the right child
                    //set the right of the now left node to take on the right of the deleted child
                    p_parent_node->get_left()->set_right(p_to_delete->get_right());
                    //if the parent node is less than the deleted node's data, update the right to point to the right node
                    if(p_parent_node->get_data()<p_to_delete->get_data()){
                        p_parent_node->set_left(p_to_delete->get_right());
                    }
            break;   
        }
    }
};


void testcase_0(){
    tree x;
    x.insert(8);
    x.insert(6);
    x.insert(7);
    x.insert(9);

    cout << "\n--------------TESTCASE 0--------------" << endl;
    x.print();
    x.delete_node( x.find(6) );
    x.print();

    // make sure the tree is still valid:
    if (x.check_tree())
        cout << "\nthe tree is still valid\n" <<endl;
    else
        cout << "\nthe tree is no longer valid\n" << endl;
}

void testcase_1(){
    tree x;
    x.insert(9);
    x.insert(8);
    x.insert(14);
    x.insert(7);
    x.insert(4);
    x.insert(6);
    x.insert(11);

    cout << "\n--------------TESTCASE 1--------------" << endl;
    x.print();
    x.delete_node( x.find(7) );
    x.delete_node( x.find(11) );
    x.delete_node( x.find(8) );
    x.print();

    // make sure the tree is still valid:
    if (x.check_tree())
        cout << "\nthe tree is still valid\n" <<endl;
    else
        cout << "\nthe tree is no longer valid\n" << endl;
}

void testcase_2(){
    tree x;
    x.insert(50);
    x.insert(30);
    x.insert(70);
    x.insert(20);
    x.insert(40);
    x.insert(15);
    x.insert(25);
    x.insert(35);
    x.insert(45);
 
    cout << "\n--------------TESTCASE 2--------------" << endl;
    x.print();
    x.delete_node( x.find(30) );
    x.print();

    x.delete_node( x.find(35) );
    x.print();

    // make sure the tree is still valid:
    if (x.check_tree())
        cout << "\nthe tree is still valid\n" <<endl;
    else
        cout << "\nthe tree is no longer valid\n" << endl;
}

void testcase_3(){
    tree x;
    x.insert(50);
    x.insert(30);
    x.insert(70);
    x.insert(20);
    x.insert(40);

    cout << "\n--------------TESTCASE 3--------------" << endl;
    x.print();
    x.delete_node( x.find(50) );
    x.print();

    // make sure the tree is still valid:
    if (x.check_tree())
        cout << "\nthe tree is still valid\n" <<endl;
    else
        cout << "\nthe tree is no longer valid\n" << endl;
}

void testcase_4(){
    tree x;
    x.insert(50);
    
    cout << "\n--------------TESTCASE 4--------------" << endl;
    x.print();
    x.delete_node( x.find(60) );
    x.print();

    // make sure the tree is still valid:
    if (x.check_tree())
        cout << "\nthe tree is still valid\n" <<endl;
    else
        cout << "\nthe tree is no longer valid\n" << endl;
}


int main(int argc, char** argv){
    if (argc != 2){
        cout << "ERROR: correct usage is ./lab_07 N, where N is 0, or 1" << endl;
        return -1;
    }

    int opt = stoi(argv[1]);

    switch (opt){
        case 0: testcase_0(); break;
        case 1: testcase_1(); break;
        case 2: testcase_2(); break;
        case 3: testcase_3(); break;
        case 4: testcase_4(); break;
        default: cout << "error: testcase value must be 0, 1, 2, 3, or 4" << endl; break;

    }

}

