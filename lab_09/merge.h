#ifndef MERGE_H
#define MERGE_H
#include<vector>
using namespace std;

class merge{
    private:
    vector<int> buffer;
    int copy_count;

    public:

    merge();
    void reset();
    void insert(int);
    int sort(int ind_A = 0, int ind_D = -1);
    void merge_sublists(int,int,int,int);
    void display();
    
};

#endif