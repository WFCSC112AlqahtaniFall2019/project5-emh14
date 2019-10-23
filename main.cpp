/* Ethan Harrison
 * CSC 112
 * Project 5
 * Blind Man's Bluff
 * */

#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main() {

    //creating new deck
    Deck newGame;
    //populating it in order like opening a brand new deck
    newGame.newDeck();
    //shuffle the deck
    srand(time(NULL)); //seed random generator with time
    newGame.shuffleDeck();

    //creating (empty) deck for discard pile
    Deck discardPile;

    //create two new cards for two new players
    Card playerCard;
    Card computerCard;

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int nWin = 0, nLoss = 0;


    play = true;
    while (play) {
        // take the new cards out of the deck
        playerCard = newGame.removeCard();
        computerCard = newGame.removeCard();

        //add the selected cards to discard pile
        discardPile.addCard(playerCard);
        discardPile.addCard(computerCard);

        //print discard pile
        discardPile.printCards();

        // get user's bet
        cout << "Computer's value is the " << computerCard.yourCardIs() << endl;
        invalid = true;
        while (invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if ((playerCard > computerCard && guessedHigher) || (computerCard > playerCard && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        }

        cout << "\tyour value is the " << playerCard.yourCardIs() << endl;


        invalid = true;
        while (invalid) {

            //check to see if there are cards left before looping again
            if (newGame.getNumCardsLeft() == 0) {
                cout << "Deck empty! Game over!" << endl;
                play = false;
                break;
            }
            // ask user to play again
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }

        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << " (W-L)" << endl;

    return 0;
}