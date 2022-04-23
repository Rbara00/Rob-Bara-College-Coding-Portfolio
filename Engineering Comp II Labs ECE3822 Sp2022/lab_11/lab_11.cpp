#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/*
    Robert Bara
    tuj22026@temple.edu
    04/15/2022
   
    BRIEF DESCRIPTION OF FILE CONTENTS
    This program is an implementation of a graph using a multidimensional array in cpp. The program reads the value of
    possible connections between each node from a file, and places the weight of the connection into the proper position
    in an array. For example, the shortest data file creates a graph with 2 nodes and 4 possible connections total.
    Printing the weight creates the matrix, 
                1       2
                0       3
    where a connection from Nodes A --> B could be represented at [0,1], with a weight of 2. The program allows the user
    to specify what data file to pass in and which source and target nodes to check.

    Usage:
    GIVE COMMANDS FOR HOW TO COMPILE AND RUN
        Compile: make all
        Run: ./lab_09  <arg[1]> <arg[2]> <arg[3]>
                where arg[1] specifies which data file to load,
                where arg[2] specifies the source node to check for a connection
                where arg[3] specifies the target node to check for a connection

                Possible arguments:
                arg[1] can be 0, 1, 2, corresponding to the data files in the directory from smallest to largest
                arg[2] can be 0 to N_nodes-1, corresponding to the target source node letter, for example 0=A, 1=B, 2=C, 3=D in a 4x4
                arg[3] can be 0 to N_nodes-1, corresponding to the target destination node letter, for example 0=A, 1=B, 2=C, 3=D in a 4x4

*/



/*  This class is simply for sorting out the contents of the file. 
    It stores all the contents to a vector and pops them to their 
    appropriate position in the graph.
*/
class datacollection{
    private:
    vector<unsigned int> data;
    public:
    datacollection(){       
        data.clear();
    }
    void push_back(int x){
        data.push_back(x);
    }
    unsigned int pop_front(){               //returns and removes the front element of the vector
        unsigned int x = (data.front());
        data.erase(data.begin());
        return x;
    }
    unsigned int size(){
        return data.size();
    }
};

//function definitions
bool check_connection(unsigned int** graph, unsigned int source, unsigned int target);
bool check_indirect(unsigned int** graph, unsigned int source, unsigned int target, unsigned int original_source, bool print_flag);

int main(int argc, char** argv){
    string dir_name = "/data/courses/ece_3822/current/lab_11/";
    string file_name;
    unsigned int n_nodes;
    unsigned int n_edges;
    unsigned int source, target;

    // parse the command line inputs
    if (argc != 4){
        cout << "incorrect number of commandline inputs" << endl;
        return 1;
    }

    file_name = argv[1];        // grab the file name
    source = stoi(argv[2]);     // grab the source name
    target = stoi(argv[3]);     // grab the target name

    //determine which file to be loaded in
    switch (stoi(file_name)){
    case 1: file_name="data_file_01.txt";
        break;
    case 2: file_name="data_file_02.txt";
        break;
    default: file_name="data_file_00.txt";
        break;
    }

    // sample code to show how to read from the file
    // -> you must read data from the file and populate
    // -> the "graph" variable. don't forget to allocate
    // -> memory for it

    fstream myfile(dir_name + file_name, ios_base::in);
    unsigned int a;
    cout<<"Loading from File: "<<file_name<<endl;
    datacollection data;

    while (myfile >> a){
        data.push_back(a);
        }
    myfile.close();
    
    //get the size of the graph
    n_nodes=(data.pop_front());
    cout<<"Graph is "<<n_nodes<<"x"<<n_nodes<<" large"<<endl;

    //If the user's inputs for source and destination exceed the size of the graph, return an error
    if(source>=n_nodes){
        cout<<"Source exceeds maximum nodes"<<endl;
        return 1;
    }
    if(target>=n_nodes){
        cout<<"Target exceeds maximum nodes"<<endl;
        return 1;
    }

    //  Otherwise, continue the program
    //  Declare the graph and intialize to 0's
    unsigned int** graph=new unsigned int*[n_nodes];
    for (int row = 0; row < n_nodes; ++row){
        graph[row] = new unsigned int[n_nodes];
    }
    //Pop data from the data queue vector into their appropriate edge locations
    for(int i=0;i<n_nodes;i++){
        for(int j=0;j<n_nodes;j++){
            graph[i][j]=data.pop_front();
        }
    }

    //Printing all elements of the graph
    for(int j=0;j<n_nodes;j++){
        cout<<endl;
        for(int k=0;k<n_nodes;k++){
            cout<<graph[j][k]<<"\t";
        }
    }
    cout<<endl;
    cout<<endl;
  
    // now that everything is in memory, check to see whether there
    // is a connection between source and target
    bool result = check_connection(graph,source,target);
    if(result==true)
        cout<<"There is a connection between Src:"<<(char)(source + 'A')<<"="<<source<< " and Dst:"<<(char)(target + 'A')<<"="<<target<<endl;
    else 
        cout<<"There is no connection between Src:"<<(char)(source + 'A')<<"="<<source<< " and Dst:"<<(char)(target + 'A')<<"="<<target<<endl;
    return 0;
}

//This function checks for a conenction between nodes in the graph 
bool check_connection(unsigned int** graph, unsigned int source, unsigned int target){
    bool return_val=false;
    //special case, a direct connection to itself
    if(source == target){
        if(graph[source][target]>0){
            cout<<"This is a direct connection with itself "<<endl;
            return_val=true;
        }
    }

    //check for a direct connection
    if(graph[source][target]>0){
        cout<<(char)(source + 'A')<<" -"<<graph[source][target]<<"-> "<<(char)(target + 'A')<<endl;
        return_val=true;
    }

        //check for an indirect connection, an example of this, run ./lab_11 1 1 1, checks for B->B
        //this function works for when there is 1 indirect node that completes the path,
        //however if we had a case for example ./lab_11 2 0 1, checks for A->B, this could only be reached by
        //A->E->B->A, which will not work. I tried to correct this with some recursion
        //but had no luck.
        else if(check_indirect(graph,source,target,source,false)){
            cout<<(char)(source + 'A');
            return_val=check_indirect(graph,source,target,source,true);
            cout<<(char)(target + 'A')<<endl;
            return_val=true;
        }            
    return return_val;
}

//This function is supposed to check if there are an indirect path to the target node
bool check_indirect(unsigned int** graph, unsigned int source, unsigned int target, unsigned int original_source, bool print_flag){
    bool return_val=false;
    //iterate through possible connections
    for(int j=0;j<sizeof(graph[0][0]);j++){
        //check if a possible source connection can reach the target, if not loop again to the next one
        if(graph[source][j]>0){
            if((graph[source][j]>0) && (graph[j][target]>0)){
                    if(print_flag==true){
                        cout<<" -"<<graph[source][j]<<"-> "<< (char)(j + 'A')<<" -"<<graph[j][target]<<"-> ";
                    }
                    return_val=true;
                    break;
            }
            //keeping track if we have been to this node before
            if((source==original_source)&&(target != original_source)) j++;

        //otherwise, check if that connection has a possible connection to the target
        // by setting the possible source connection as the new source
        else if(check_indirect(graph,j,target,original_source,true)){
            return_val=check_indirect(graph,j,target,original_source,true);
            break;
        }
        }
    }
    return return_val;   
}