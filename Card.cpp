#include "Card.h"

//Default constructor
Card::Card(){
    rank = 0;
    suit = 0;
}

//Alternate Constructor
Card::Card(int cardRank, int cardSuit){
    rank = cardRank;
    suit = cardSuit;
}

//Overloaded comparison operator
    //The rank is more important than the suit
    //Aces are low and Queens are high, so that A<2<...<10<J<K<Q
    //Suits are ordered alphabetically, so that Clubs < Diamonds < Hearts < Spades
bool Card::operator>(Card opponent){
    if (rank == opponent.rank){// if the ranks of the two cards are equal
        return suit > opponent.suit;// the suit will be evaluated
    }

    return rank > opponent.rank;//evaluate ranks if they are different
}

//Returns a string specifying the value of the card
string Card::yourCardIs(){
    return ranks[rank] + " of " + suits[suit];
}