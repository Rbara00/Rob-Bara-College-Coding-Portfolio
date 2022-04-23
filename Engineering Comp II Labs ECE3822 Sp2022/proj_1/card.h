/*
  Header file for the <<card>> class
*/

#include<iostream>
#ifndef CARD_H
#define CARD_H

enum suit_type {clubs, diamonds, hearts, spades}; //each suit type

class card{
private:
    int value;        //value of selected card, can range 1-13(king) or 0 which is unidentified
    suit_type suit;   //suit type of selected card
public:
    card();                 //constructor for unidentified card
    card(int,suit_type);    //constructor for a card that maps the passed in value and suit to the card
    void set_card(int,suit_type); //sets the current card to the selected value and suit
    int get_value();        //getter for the card's value
    suit_type get_suit();   //getter for the card's suit
};

std::ostream& operator <<(std::ostream& , card);


#endif
