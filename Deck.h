/* Ethan Harrison
 * CSC 112
 * Project 5
 * Blind Man's Bluff
 * */

#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {

private:
    Card* cards; //pointer to array of cards
    int arraySize; //physical size of the array
    int cardsLeft; //logical size of the array

public:
    //Constructor for initializing the game
    Deck();

    //The Big Three:

    //1. Destructor
    ~Deck();
    //2. Copy constructor
    Deck(const Deck& copyDeck);
    //3. Copy assignment operator
    Deck& operator=(Deck deckToCopy);


    //Populates the deck with 52 cards
    void newDeck();

    //Shuffles the cards in the deck
    void shuffleDeck();

    //Remove a card from the deck
    Card removeCard();

    //Adds a card to the deck
    bool addCard(Card newCard);

    //getter for number of cards left
    int getNumCardsLeft();

    //print cards in the deck
    void printCards();
};


#endif //BLINDMANSBLUFF_DECK_H
