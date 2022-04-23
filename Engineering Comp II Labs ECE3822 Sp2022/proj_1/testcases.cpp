/*
  TESTCASES
  DO NOT EDIT TESTCASE_0 or TESTCASE_1
*/

#include<iostream>
#include "cards.h"
#include "card.h"
using namespace std;

/////////////////////////////////////////////////////////////////////
// TESTCASE_0

void testcase_0(){
    string suits[]={"diamonds","hearts","clubs","spades"};
    
    cout << "\n***** Testcase 0 *****" << endl;
    cout << "\n\tTests the <<card>> class" << endl;

    cout << "\n\t[1] Create an empty card and print it:" << endl;
    card x;
    cout << "\t\t" << x << endl;

    cout << "\n\t[2] Create cards of the four different suits and print them:" << endl;
    cout << "\t\t" << card( 4,hearts) << endl;
    cout << "\t\t" << card(14,spades) << endl;
    cout << "\t\t" << card(11,diamonds) << endl;
    cout << "\t\t" << card( 8,clubs) << endl;

    cout << "\n\t[3] Create a card, and then retrieve its value and suit:" << endl;
    x.set_card(3,spades);
    cout << "\t\t" << x.get_value() << " of " << suits[x.get_suit()] << endl;

    cout << "\n\t[4] Test set_card on out-of-range card:" << endl;
    x.set_card(-1,diamonds);
    cout << "\t\tset_card(-1,diamonds) -> " << x << endl;
}



/////////////////////////////////////////////////////////////////////
// TESTCASE_1

void testcase_1(){
  
    cout << "\n***** Testcase 1 *****" << endl;
    cout << "\n\tTests the <<cards>> class" << endl;

    cout << "\n\t[1] Create an empty pile of cards and display the results:" << endl;
    cards myPile;
    myPile.display();


    cout << "\n\t[2] Add two cards to an empty pile and display the results:" << endl;
    myPile.add_new_card( card( 9, hearts) );
    myPile.add_new_card( card(13, diamonds) );
    myPile.display();
    cout << "\nThere are myPile.size() = " << myPile.size() << " cards in the pile" << endl;

    cout << "\n\t[3] Clear the deck and verify it is empty" << endl;
    myPile.clear_all();
    myPile.display();

    cout << "\n\t[4] Create a complete deck, display the first 5 cards" << endl;
    myPile.create_complete_deck();
    myPile.display(5);
    cout << "There are myPile.size() = " << myPile.size() << " cards in the pile" << endl;


    cout << "\n\t[5] Shuffle the deck and re-display the first 5 cards" << endl;
    myPile.shuffle();
    myPile.display(5);

    cout << "\n\t[6] Deal the top two cards off the deck, display the dealt cards and the first five cards remaining in the pile" << endl;
    cout << "\tdealt cards are: "<< endl;
    cout << "\t" << myPile.deal_top_card() << endl;
    cout << "\t" << myPile.deal_top_card() << endl;
    cout << "\n\tThe top of the pile now contains: " << endl;
    myPile.display(5);
    cout << "There are myPile.size() = " << myPile.size() << " cards in the pile" << endl;


    cout << "\n\t[7] Try to deal from an empty pile:" << endl;
    myPile.clear_all();
    card y = myPile.deal_top_card();
    cout << "the card dealt from the empty hand is: " << y << endl;

}


/////////////////////////////////////////////////////////////////////
// TESTCASE_2
// Playing a game

void testcase_2(){
    /*
      Write a testcase that simulates playing a game between four players and a dealer.
      -> The dealer should have a complete deck of 52 cards
      -> Then the dealer should deal five cards to each of the four players
      -> Each player should then identify their best card. The best card is identified as having the highest
      value and the highest suit (spades > hearts > diamonds > clubs)
      -> Finally, compare the best cards from each of player to determine which player is the winner. Display
      which player is the winner and what was the winning card
     */
    
    cards dealer,winner;
    cards p1,p2,p3,p4;
    card  p1Best, p2Best, p3Best, p4Best;

    cout << "\n***** Testcase 3 *****" << endl;
    cout << "\n\tTests simulating a game between 4 players and dealer" << endl;
    //Dealer gets a complete deck of 52 cards and shuffles them
    dealer.create_complete_deck();
    dealer.shuffle();
    cout << "\n\t[1] Dealer has a complete deck of "<<dealer.size()<<" shuffled cards" << endl;
    
    cout << "\n\t[2] Dealer deals 5 cards to 4 players "<< endl;
    //deal 5 cards to 4 players
    for(int i=0;i<=4;i++){
      p1.add_new_card(dealer.deal_top_card());
      p2.add_new_card(dealer.deal_top_card());
      p3.add_new_card(dealer.deal_top_card());
      p4.add_new_card(dealer.deal_top_card());
    }
    //Display each players cards
    cout<<"Player 1"<<endl;
    p1.display();
    
    cout<<"Player 2"<<endl;
    p2.display();
    
    cout<<"Player 3"<<endl;
    p3.display();
    
    cout<<"Player 4:"<<endl;
    p4.display();

    //identify best cards
    cout << "\n\t[3] Identifying each player's best card "<< endl;
    p1Best=p1.bestCard();
    cout<<"Player 1's Best Card: "<<p1Best<<endl;
    
    p2Best=p2.bestCard();
    cout<<"Player 2's Best Card: "<<p2Best<<endl;

    p3Best=p3.bestCard();
    cout<<"Player 3's Best Card: "<<p3Best<<endl;

    p4Best=p4.bestCard();
    cout<<"Player 4's Best Card: "<<p4Best<<endl;


    cout << "\n\t[4] Compare each player's best card, determine the winner "<< endl;

  //load the best cards into a winning pile to determine who is the winner
   winner.add_new_card(p1Best);
   winner.add_new_card(p2Best);
   winner.add_new_card(p3Best);
   winner.add_new_card(p4Best);

   //determine who is the winner
   winner.isWinner();

}

