/* Ethan Harrison
 * CSC 112
 * Project 5
 * Blind Man's Bluff
 * */

#include <iostream>
#include "Deck.h"

//Constructor for initializing the game
Deck::Deck() {
    //cout << "default constructor called" << endl;

    cards = new Card[52];
    arraySize = 52;
    cardsLeft = 0;
}

//The Big Three:

//1. Destructor
Deck::~Deck() {
    //cout << "destructor called" << endl;
    delete[] cards;
}

//2. Copy constructor
Deck::Deck(const Deck &copyDeck) {
    //cout << "Copy constructor called" << endl;

    //deep copy for each card
    cards = new Card[52]; //allocate memory for cards again in heap
    for (int i = 0; i < arraySize; i++) {
        cards[i] = copyDeck.cards[i];
    }

    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
}

//3. Copy assignment operator
Deck &Deck::operator=(Deck deckToCopy) {
    //cout << "Copy assignment operator called" << endl;

    swap(cards, deckToCopy.cards); //built-in swap
    //primitive values do not need swap function
    arraySize = deckToCopy.arraySize;
    cardsLeft = deckToCopy.cardsLeft;

    return *this;
}


//Populates the deck with 52 cards
void Deck::newDeck() {
    //iterate for every suit (s)
    for (int s = 0; s < 4; s++) {
        //iterate for every rank (r)
        for (int r = 0; r < 13; r++) {
            Card newCard(r, s);
            addCard(newCard);
        }
    }

    // Set the cardsLeft to 52
    cardsLeft = 52;
}

//Shuffles the cards in the deck
void Deck::shuffleDeck() {
    // shuffle by performing cardsLeft^2 swaps of two randomly chosen cards in the deck
    for (int i = 0; i <= cardsLeft * cardsLeft; i++) {
        //generates random positions and swaps them
        swap(cards[rand() % cardsLeft], cards[rand() % cardsLeft]);
    }
}

//Remove a card from the deck
Card Deck::removeCard() {
    //returns card at the logical end of the array
    return cards[--cardsLeft];
}

//Adds a card to the deck
bool Deck::addCard(Card newCard) {
    if (cardsLeft == 52) {
        return false;
    }
    //Post-increment cardsLeft before adding to deck
    cards[cardsLeft++] = newCard;
    return true;
}

//getter for number of cards left
int Deck::getNumCardsLeft() {
    return cardsLeft;
}

//print cards in the deck
void Deck::printCards() {
    for (int i = 0; i < cardsLeft; i++) {
        cout << cards[i].yourCardIs() << endl << endl;
    }
}
