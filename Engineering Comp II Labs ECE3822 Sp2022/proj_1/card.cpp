#include<iostream>
#include "card.h"
using namespace std;

card::card(int v, suit_type s){
    // constructor that creates a card with specified value and suit
    value=v;//value of the card corresponds to the passed in value
    suit=s;//card's suit corresponds to passed in string to enum
}

card::card(){
    // constructor for an unspecified card
    // when set to '0' the 'value' is flagged as 'undefined'
    value=0;
}

void card::set_card(int v, suit_type s){
    // set the value and suit of a card
    // be sure to check the specified value to make sure it is a valid number
    value=(v>=0||v<=15)?v:0; //evaluates if v is a valid number which lies in a range of 1-14, otherwise the value is set to 0 (undefined) 
    suit<<(v>=0||v<=3)?s:(v=0);//evaluates if the suite is a valid suit_type (enum) otherwise sets the card to undefined
}

int card::get_value(){
    // simply return the value of the card
    return value;
}

suit_type card::get_suit(){
    // simply return the suit of the card
    return suit;
}

std::ostream& operator <<(std::ostream& os, card c){

/*
  DO NOT EDIT THIS FUNCTION
  This function allows us to do cout with a card
  For example:
  card x( 3,hearts);
  cout << x << endl;
*/

    int val = c.get_value();
    suit_type suit = c.get_suit();

    // special case for undefined card
    if (val==0){
	os << "undefined card";
	return os;
    }
    
    switch( val )
    {
    case 11: os << "jack";  break;
    case 12: os << "queen"; break;
    case 13: os << "king";  break;
    case 14: os << "ace";   break;
    default: os << val;
    }

    os << " of ";

    switch ( suit )
    {
    case diamonds : os << "diamonds"; break;
    case hearts : os << "hearts"; break;
    case clubs : os << "clubs"; break;
    case spades: os << "spades"; break;
    }
	    
    return os;
}	
