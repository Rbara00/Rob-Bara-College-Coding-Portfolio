#ifndef HEAP_H
#define HEAP_H

class binary_heap{

    private:
    int* buffer;
    int buffsize;
    int swapCnt;
    int n_items;
    int left(int);
    int right(int);
    int parent(int);
    
    void swap(int, int b);
    void bubble_up(int);
    bool is_valid_index(int);    
    bool has_children(int);
    int get_largest_child(int);  
    void bubble_down(int);
    
    public:
    binary_heap();
    void insert(int);    
    void print_buffer();    
    int pop();
    int sort();
    void reset(int);
};


#endif