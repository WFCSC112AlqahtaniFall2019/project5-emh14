/* Ethan Harrison
 * CSC 112
 * Project 5
 * Blind Man's Bluff
 * */

#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H

#include <string>

using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "King", "Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

class Card {

private:
    int rank; // card rank variable
    int suit; // card suit variable

public:
    //Default constructor
    Card();

    //Alternate Constructor
    Card(int cardRank, int cardSuit);

    //Overloaded comparison operator
        //The rank is more important than the suit
        //Aces are low and Queens are high, so that A<2<...<10<J<K<Q
        //Suits are ordered alphabetically, so that Clubs < Diamonds < Hearts < Spades
    bool operator>(Card opponent);

    //Returns a string specifying the value of the card
    string yourCardIs();
};


#endif //BLINDMANSBLUFF_CARD_H
