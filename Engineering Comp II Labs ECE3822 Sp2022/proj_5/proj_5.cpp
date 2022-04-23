#include <iostream>
#include "/data/courses/ece_3822/current/include/hash_table.hxx"
#include "/data/courses/ece_3822/current/include/linked_list.hxx"
#include<string>
/*proj_5.cpp
   Robert Bara
   tuj22026@temple.edu
   04/21/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS
   This file implements a graph as a sort of social network and uses 3 classes to make this example happen. A Profile class holds the name, 
   visited status, and friendslist of a member. The friends class is specifically a modified linked list class designed to handle the 
   member's friendslist, this also inherits a linked_list. The final class is the graph itself, ultimately while the search time 
   is less efficient than using other methods of storing such as a hash table or binary search tree, this graph implementation
   inherits a linked list of pointers to member's profiles to make the network. A driver function is added for testing the graph's ability
   to add members to the network, add a direct connection between members, search for a direct connection, and search for direct/indirect
   connections while returning the distance between each member.

   Usage:
   GIVE COMMANDS FOR HOW TO COMPILE AND RUN
    Compile: make all
    Run:    ./proj_5 
*/

using namespace std;

//Class that inherits a linked list to modify the class and represent a profile's friend list
class friends:public linked_list<string>{
    public:
    //inserts a friend to the linked list of friends
    void add_friend(string n){
        insert(n);
    }

    //clears the friendlist
    void clear(){
        while(!is_empty()){
            pop_front();
        }
    }

    // remove a node from the front of the list
    string pop_front() {
        if (head == NULL) {
            return NULL;
        } else {
            string x = head->get_payload();
            node* temp = head;
            head = head->get_next();
            delete temp;
            len--;
            return x;
        }
    }

    //Modified search function to try and catch if a member does not have a payload
    //I attempted to use this to try and fix the mutual of a mutual friend problem
    //since it crashes within the if statement within the linked_list.hxx search function
    bool search(string n){
        bool return_val=false;
        node* temp = head;
        while (temp != NULL) {
            try{
                if(temp->get_payload()==n){
                    return_val= true;
                }
                temp = temp->get_next();
            }
            catch(...){break;}

        }
        return return_val;
    }
};

//Class for a profile consisting of the individual's attributes and friend's list
class profile{
    private:
    string name;
    bool visited;
    public:
    friends friendlist;
    //creates a profile for the current person
    profile(string n){
        name=n;
        visited=false;
        friendlist.clear();
        friendlist.add_friend(n);
    }
    //returns a pointer to this person's profile
    string get_name(){ return name; }
    //sets the name of the member
    void set_name(string n){ name=n; }
    //adds a member as a friend to this person's friendgroup
    void add_friend(string n){ friendlist.add_friend(n); }
    //returns true if member is found in friendlist
    bool find_friend(string n){ return friendlist.search(n); }
    //sets if the member is visited when iterating through the friendslist
    void set_visited(bool status){ visited=status;}
    //returns the status of the member being visited
    bool get_visited(){ return visited;}
};

//Graph implementation using a linked list of pointers to profiles
class graph: protected linked_list<profile*>{
    private:
    //checks that both member's profile's are not Null and exist in the network
    bool valid_members(profile* p1,profile* p2){
        bool ret_val=false;
        if((p1!=NULL)&&(p2!=NULL)) ret_val=true;
        return ret_val;
    }
    
    //returns true if member is found in friendlist
    bool search(string name){
        bool return_val=false;
        node* temp = head;
        //iterate through every node starting at the head and check for correct name
        while (temp != NULL) {
            if (temp->get_payload()->get_name() == name) {
                return_val=true;        //return true if correct member is found in list
            }
            temp = temp->get_next();
        }
        return return_val;
    }

    //returns a pointer to the member, if they exist in the network
    profile* get_member(string name){
        profile* return_val=NULL;
        node* temp = head;
        //iterate through every node starting at the head and check for correct name
        while (temp != NULL) {
            if (temp->get_payload()->get_name() == name) {
                return_val=temp->get_payload();     //return member if found in list
            }
            temp = temp->get_next();
        }
        return return_val;
    }

    //checks if one member's profile is found in another member's profile's friendlist
    bool valid_connection(profile* p1, profile* p2){
        bool return_val=false;

        //check if they have each other as friends
        bool f1=p1->find_friend(p2->get_name());
        bool f2=p2->find_friend(p1->get_name());

        //Ensure it is a direct, bidirectional connection
        if((f1==true) && (f2==true)){
            return_val=true;
            cout<<p1->get_name()<<" and "<<p2->get_name()<<" are friends"<<endl;   
        }
        else 
            cout<<p1->get_name()<<" and "<<p2->get_name()<< " are not friends"<<endl;
        
        return return_val;
    }

    //this function checks if member 2 is a mutual friend of member 1 
    int check_friends(profile* p1, string n2, int return_val=0){
        //create a temp list to iterate over
        friends tmp_list=p1->friendlist;                

        //iterate over friendslist until we've run out of friends
        while(tmp_list.is_empty()==false){
            //get current friend
            string temp_name=tmp_list.pop_front();
            profile* temp_friend=get_member(temp_name);
            //as long as the friend user is not themselves
            if(temp_friend->get_name()!=p1->get_name()){
               
                //Priority logic:if the user only has 1 friend and it is not the friend we are looking for, break
                if((temp_friend->get_name()!=n2)&&(tmp_list.is_empty()==true)) break;

                //check if we have been here before, if not, set it to true
                if(temp_friend->get_visited()==false){
                    temp_friend->set_visited(true);
                    //as long as the friend exists, increment the distance by 1 since they are friends
                    return_val+=1;    
                    //otherwise check if they are mutual friends
                    cout<<p1->get_name()<<" and "<<temp_friend->get_name()<<" are friends, is "
                        <<temp_friend->get_name()<<" a friend of "<<n2<<"?"<<endl;

                    //Priority logic:if the friend is the friend we are looking for then its a direct connection, break
                    if(temp_name==n2){
                        break;
                    }  

                    //recurse the function to check more member's friendlists, if the  return val is not
                    //-1, then a connection is found, and if return val is greater than 1, then it is a mutual
                    //connection and the distance will be incremented for each mutual friend we iterate through 
                    if(check_friends(temp_friend,n2,return_val)>1){ 
                        return_val++;
                        break;
                    }
                    else return_val=-1;         //if there is no connection found, reset to -1
            }
            }
        }
        return return_val;
    }

    //initializes all profile's visited statuses to false
    void set_visited_status(){
        node* temp = head;
        //iterate through every node starting at the head and initialize visited to false
        while (temp != NULL) {
            temp->get_payload()->set_visited(false); 
            temp = temp->get_next();
        }
    }

    //checks for the distance between two memembers
    int distance_check(string n1, string n2, int return_val=-1){
        //set all members of the graph's visited statuses to false
        set_visited_status();

        //check if member's exist within the graph
        profile* p1=get_member(n1);
        profile* p2=get_member(n2);

        //Priority Logic, if they are themselves
        if(n1==n2){
            if(valid_members(p1, p2)) cout<<n1<<" is connected to themselves"<<endl;
            return_val=0;
        } 

        //check for direct connection
        else if(are_friends(n1,n2)) return_val=1;

        //check each friend in member 1's friendlist to see if they are friends
        else if(valid_members(p1,p2)){
            //run as long as both members exist
            return_val=check_friends(p1, n2);
        }
        return return_val;
    }

    public:
    //adds a member to the network
    void new_member(string name){
        if(get_member(name)!=NULL){
            cout<<name<<" already exists in this network"<<endl;
        }
        else{
            profile* p1=new profile(name);
            insert(p1);
            cout<<name<<" has joined facebook!"<<endl;
        }
    }
    //adds a bidirectional connection to both member's by adding to each other's friendslist
    void new_connection(string n1, string n2){
        profile* p1=get_member(n1);
        profile* p2=get_member(n2);
        //check if both members exist 
        if(valid_members(p1,p2)){
            //adds bidirectional connection
            p1->add_friend(n2);
            p2->add_friend(n1);
        }
    }

    //checks if two members are in the network and are friends
    bool are_friends(string n1, string n2){
        bool return_val=false;
        profile* p1=get_member(n1);
        profile* p2=get_member(n2);
        //check if member's exist
        if(valid_members(p1,p2)){
            //check if their names are found in both friend's lists
            if(valid_connection(p1,p2)) return_val=true;
        }
        else cout<<"Error, 1 or more member are not found"<<endl;
        
        return return_val;
    }

    //returns the shortest distance between two people in the graph
    int distance(string n1, string n2){
        int return_val=distance_check(n1, n2);

        //I was thinking of attempting to check both distances and then return the shortest, 
        //however I was unable to get this working due to the case that I could not get
        //a mutual of a mutual case to work correctly

        //int return_b=distance_check(n2, n1);
        //if(return_b>return_val) return_val=return_b;
        return return_val;
    }
};


//Driver program for classes
int main(){
    graph graph1;
    cout<<endl<<"MEMBERS ARE JOINING THE NETWORK, WELCOME TO THE REVOLUTION"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    //----------------------------------------------------------
    //add some members to the list
    //----------------------------------------------------------
    graph1.new_member("Jerry");
    graph1.new_member("Tom");
    graph1.new_member("Popeye");
    graph1.new_member("Popeye");                //Case for a collision, adding the same user twice
    graph1.new_member("Rob");
    graph1.new_member("Poe");
    graph1.new_member("Ellen");

    //----------------------------------------------------------
    //add some direct connections between the members
    //----------------------------------------------------------
    graph1.new_connection("Jerry","Tom");          
    graph1.new_connection("Jerry","Randy");     //case for invalid user    
    graph1.new_connection("Jerry","Popeye");    //Jerry has 2 friends
    graph1.new_connection("Rob","Popeye");  
    graph1.new_connection("Rob","Poe"); 
    graph1.new_connection("Rob","Ellen");    //Rob has 3 friends, everyone else has 1 friend


    //----------------------------------------------------------
    //check to ensure the connections exist
    //----------------------------------------------------------
    cout<<endl<<"Lets see who are comrades ( •ヮ•)八(•ヮ• )"<<endl;
    cout<<"---------------------------------------------"<<endl;
    /* Based on how I interpreted the read me, users are only friends 
       if a direct bidirectional connection is established. The Distance
       function will handle indirect connections instead
    */
    graph1.are_friends("Poe","Rob");                //case where there is a direct friendship
    graph1.are_friends("Jerry","Rob");              //case where there is not a direct friendship  
    graph1.are_friends("Tom","Tom");                //A connection with themselves is valid
    graph1.are_friends("Ellen","Joe Biden");        //case where the user does not exist        


    //----------------------------------------------------------
    // checking the distance between direct/indirect connections
    //----------------------------------------------------------
    cout<<endl<<"What about the distance between homies and mutual homies?? ( ･_･)人(･_･ )"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout <<"Distance between: " <<graph1.distance("Jerry","Tom")<<endl<<endl; //case for a direct friendship
    cout <<"Distance between: " <<graph1.distance("Poe","Poe")<<endl<<endl; //case for themselves
    cout <<"Distance between: " <<graph1.distance("Jerry","Rob")<<endl<<endl; //case for a mutual friend

    //case for if a user that doesnt exist
    cout <<"Distance between: " <<graph1.distance("Jerry","Paul Blart")<<endl<<endl;

    /*This is the only case I can not seem to get working, its for a mutual of a mutual of a mutual (mutual->n*mutual) connection,
      Specifically this has to be an issue with my check_friends() function that uses recursion
    */
   // cout <<"Distance between: " <<graph1.distance("Jerry","Ellen")<<endl<<endl; 
    return 0;
}