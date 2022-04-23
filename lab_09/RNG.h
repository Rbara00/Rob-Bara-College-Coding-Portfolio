#ifndef RNG_HDR
#define RNG_HDR

class RNG{
    
    //***************************************************************
    //********** declare variables
    //***************************************************************

  private:
  
    int maxsize;
    bool *buffer;

  public:

    //***************************************************************
    //********** declare methods
    //***************************************************************
    
    RNG(int); // constructor
    int gen(); // generate non-repeating random numbers;
    void reset();
    
};

#endif