#ifndef BUBBLE_H
#define BUBBLE_H

class bubble_sort{
    public:
    bubble_sort();
    int sort();
    void reset(int);
    void insert(int);
    void print();


    private:
    void swap(int,int);
    int swap_count;
    int* buffer;
    int buffsize;
    int i_curr;
};

#endif