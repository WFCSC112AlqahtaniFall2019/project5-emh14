#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {

private:
    Card* cards; //pointer to array of cards
    int arraySize; //physical size of the array
    int cardsLeft; //logical size of the array

public:
    //Default Constructor for initializing the game
    Deck();

    //The Big Three

    //1. Destructor
    ~Deck();
    //2. Copy constructor
    Deck(const Deck& copyDeck);
    //3. Copy assignment operator
    Deck& operator = (Deck& deckToCopy);


    //Populates the deck with 52 cards
    void newDeck();

    //Shuffles the cards in the deck
    void shuffleDeck();

    //Chooses a card from the deck
    int chooseCard();

    //Adds a card to the deck
    bool addCard();
};


#endif //BLINDMANSBLUFF_DECK_H
