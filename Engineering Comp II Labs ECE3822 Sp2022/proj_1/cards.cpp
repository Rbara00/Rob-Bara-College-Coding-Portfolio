//cards class, which utilizes the class card to create a pile/deck of cards
#include "cards.h"
#include "card.h"
#include<cstdlib>

cards::cards(){
    // constructor - creates an empty pile of cards
    deckSize=0;
    pile.clear();
    cout<<"Pile Created and cleared"<<endl;
}

void cards::clear_all(){
    // reset the pile to be empty, reset the size of the deck
    pile.clear();
    deckSize=0;
}

int cards::size(){
    // return the number of cards in the pile
    return deckSize;
}

void cards::add_new_card(card c){
    // append the new card, c, to the pile, increase deck size
    pile.push_back(c);
    deckSize++;
}

card cards::deal_top_card(){
    // remove the top card from the deck
    // and return it
    card top_card;
    //if the deck is empty return an undefined card
    if(deckSize<=0) top_card=card();
    //otherwise return the top card
    else{
        top_card=pile.front();//top card will be the last element of vector since it is the last card you deal onto the deck
        pile.erase(pile.begin());//remove the index and element of the vector of cards
        deckSize=pile.size();//decrements number of cards after card is dealt
    }
    return top_card;
    
}

void cards::create_complete_suit(suit_type s){
    //add a new card to the pile from values 1 to king of the passed in suit type
    for(int i=1;i<=13;i++){
        add_new_card(card(i,s));
    }
}

void cards::create_complete_deck(){
    // create a pile of all 52 playing cards, in order
    //clear the pile first so that the deck is not addding the 52 cards on top of whatever else is already in hand
    clear_all();
    //build from bottom to top based upon suit ranking (spades>hearts>clubs>diamonds)
    create_complete_suit(diamonds);
    create_complete_suit(clubs);
    create_complete_suit(hearts);
    create_complete_suit(spades);
}

void cards::cardSwap(int card1, int card2){
    //swaps the places of two cards using a temporary card
    card temp=pile[card2];
    pile[card2]=pile[card1];
    pile[card1]=temp;
}

void cards::shuffle(){
    // randomize the order of the cards in the pile
    //perform a random swap as many times as there are cards within the deck
    for(int count=0;count<=deckSize;count++){
        int i=rand()%deckSize;//select a random index of within the deck
        int j=rand()%deckSize;//select another random index within the deck
        cardSwap(i,j);//swapcards
    }
}

int cards::suitVal(suit_type suit){
    //Returns the suit's value based on ranking from best to worst
    //(spades > hearts > diamonds > clubs)
    int suitRank=0;
    switch (suit){
        case clubs : suitRank=0; break;
        case diamonds : suitRank=1; break;
        case hearts : suitRank=2; break;
        case spades: suitRank=3; break;
    }
    return suitRank;
}

suit_type cards::getSuitType(int suitRank){
    //returns the suit based on the suit's ranking value
    suit_type suit; //From best to worst (spades > hearts > diamonds > clubs)
    switch (suitRank){
        case 0 : suit=clubs; break;
        case 1 : suit=diamonds; break;
        case 2 : suit=hearts; break;
        case 3: suit=spades; break;
    }
    return suit;
}

card cards::bestCard(){
    //Finds the best card from player's pile
    //returns the best card
    suit_type suit, prevSuit, bestSuit;
    int value=0,suitRank=0, preVal=0, prevSuitRank=0, bestVal=0;
    card current_card, bestCard;
    
    //compares every card in pile
    for(int i=0;i<=pile.size();i++){
        //select a card from the pile    
        current_card=deal_top_card(); 

        //obtain the suit, suit's ranking, and value of card
        suit=current_card.get_suit();   
        suitRank=suitVal(suit);
        value=current_card.get_value(); 

        //check for highest suit (spades > hearts > diamonds > clubs)
            if(suitRank>prevSuitRank){
                prevSuit=suit;//set the best card's suit
                prevSuitRank=suitVal(suit);//update the suit's ranking
                preVal=value;//as long as the suit is greater than the previous suit, automatically update the value
            }
            //if the suit is the same, update the max value only if the current card's
            //value is greater than the previous max card's value        
            else if(suitRank==prevSuitRank){
                if((value>=preVal)||(preVal==0)) preVal=value;
                else preVal=preVal;
            }
    }
    //set the best value to be the highest previous value within the highest suit
    bestSuit=getSuitType(prevSuitRank);  
    bestVal=preVal;
    //select the best card and return
    bestCard=card(bestVal,bestSuit);
    return bestCard;   
}


void cards::isWinner(){
    card winner, p1Best,p2Best,p3Best,p4Best;
    //gather each player's best card for deciding who wins
    p1Best=pile[0];
    p2Best=pile[1];
    p3Best=pile[2];
    p4Best=pile[3];
    //Determine the best card of each player's best cards 
    winner=bestCard();
    cout<<endl<<"The best card is "<<winner<<", therefore ";

    //Compare which player owns the winning card, print win statement
    if(isCardEqual(winner,p1Best)==1) cout<<"Player 1 wins! :)"<<endl;
    else if(isCardEqual(winner,p2Best)==1) cout<<"Player 2 wins! :)"<<endl;
    else if(isCardEqual(winner,p3Best)==1) cout<<"Player 3 wins! :)"<<endl;
    else if(isCardEqual(winner,p4Best)==1) cout<<"Player 4 wins! :)"<<endl;
}

bool cards::isCardEqual(card c1, card c2){
    //Takes in two cards and compares their value and suit
    int v1=c1.get_value();
    int v2=c2.get_value();
    int s1=c1.get_suit();
    int s2=c2.get_suit();
    //if both cards have the same value and suit, return true
    if((v1==v2)&&(s1==s2)) return 1;
    //otherwise return false
    else return 0;
}

void cards::display(int n){
    // display the cards in the pile
    // if "n" is specified, eg << myPile.display(5) >> then display the first n cards in the pile
    cout<<"Cards:";
    for(int i=0;i<(n%deckSize);i++){
        cout<<"\t"<<pile[i]<<endl;
    }
}

void cards::display(){
    // display the cards in the pile
    // if "n" is not specified, eg << myPile.display() >> then display all cards in the pile
    cout<<"Cards:";
    for(int i=0;i<deckSize;i++){
        cout<<"\t"<<pile[i]<<endl;
    }
}
