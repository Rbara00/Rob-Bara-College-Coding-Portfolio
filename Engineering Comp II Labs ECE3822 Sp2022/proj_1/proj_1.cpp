/* proj_1.cpp

   Rob Bara
   tuj22026@temple.edu
   1/27/2022
   
   BRIEF DESCRIPTION OF FILE CONTENTS:
   -The first test case 0 functions as a driver to test the card class
   -The second test case 1 functions as a driver to test the cards class
   -The third test case 2 functions as a game which rules are as follows:
         The game allows for four players and a dealer.
      -> Then the dealer deals five cards to each of the four players from a deck of 52 cards
      -> Each player should then identify their best card. The best card is identified as having the highest
         value and the highest suit (spades > hearts > diamonds > clubs)
      -> Finally, the best cards from each of player are compared to determine the best card which player is the winner. 

   Usage:
   Compiling: 
              make all              //compiles all files and makes an executable
   Running:   ./proj_1 (argument)   //argument can be 0,1, or 2 and corresponds to the
                                      testcases in this driver program
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

#include "cards.h"
#include "card.h"
#include "testcases.h"

using namespace std;

int main(int argc, char **argv){
    srand(time(nullptr));
    
    assert(argc==2);
    int option = stoi(argv[1]);
    string errStr="error";
    switch (option){
    case 0: testcase_0(); break;
    case 1: testcase_1(); break;
    case 2: testcase_2(); break;
    default: cout << errStr << endl; break;
    }

    cout << endl;
    
    return 0;
}

