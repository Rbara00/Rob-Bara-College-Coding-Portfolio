//header file for cards class, which controls a pile of cards
#ifndef CARDS_H
#define CARDS_H
#include<vector>
#include "card.h"

using namespace std;

class cards{

private:
    vector<card> pile;                      //a pile of cards
    int suitVal(suit_type);                 //returns the corresponding ranking value of the suit
    suit_type getSuitType(int suitRank);    //returns the corresponding suit type to the suit's rank value
    void cardSwap(int,int);                 //swaps two cards
    void create_complete_suit(suit_type);   //creates a complete deck 1-king of the corresponding suit
    bool isCardEqual(card,card);            //compares two cards if they are equal
        
public:
    cards();                                //constructor to create an empty pile of cards
    int size();                             //returns the deck size
    void shuffle();                         //shuffles the deck
    void add_new_card(card);                //add a new card to the deck
    void clear_all();                       //clears out the deck
    void create_complete_deck();            //creates a complete deck based upon correct suit order
    card deal_top_card();                   //deals the top card of the deck
    card bestCard();                        //determines the best card of a pile
    void display(int);                      //displays n'th number of cards in a pile
    void display();                         //displays all cards in a pile
    void isWinner();                        //determines the winner
    int deckSize;                           //the size of the pile of cards            


};

#endif
