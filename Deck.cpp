#include <iostream>
#include "Deck.h"

//Constructor for initializing the game
Deck::Deck() {
    cards = new Card[52];
    arraySize = 52;
    cardsLeft = 0;
}

//The Big Three:

//1. Destructor
Deck::~Deck() {
    delete[] cards;
}

//2. Copy constructor
Deck::Deck(const Deck &copyDeck) {
    cards = copyDeck.cards;
    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
}

//3. Copy assignment operator
Deck &Deck::operator=(Deck deckToCopy) {
    swap(cards, deckToCopy.cards); //built-in swap

    //primitive values do not need swap function
    arraySize = deckToCopy.arraySize;
    cardsLeft = deckToCopy.cardsLeft;

    return *this;
}


//Populates the deck with 52 cards
void Deck::newDeck() {
    //iterate for every suit
    for (int s = 0; s < 4; s++) {
        //iterate for every rank
        for (int r = 0; r < 13; r++) {
            Card *newCard = new Card(r, s);
            addCard(*newCard);
        }
    }

    // Set the cardsLeft to 52
    cardsLeft = 52;
}

//Shuffles the cards in the deck
void Deck::shuffleDeck() {
    for (int i = 0; i <= cardsLeft * cardsLeft; i++) {
        //generates random positions and swaps them
        swap(cards[rand() % cardsLeft], cards[rand() % cardsLeft]);
    }
}

//Remove a card from the deck
Card Deck::removeCard() {
    //returns card at the logical end of the array
    return cards[cardsLeft--];
}

//Adds a card to the deck
bool Deck::addCard(Card newCard) {
    if (cardsLeft == 52) {
        return false;
    }
    //pre-increment cardsLeft before adding to deck
    cards[++cardsLeft] = newCard;
    return true;
}

//getter for number of cards left
int Deck::getNumCardsLeft(){
    return cardsLeft;
}