#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main() {

    //creating new deck and populating it
    Deck* newGame = new Deck();
    newGame->newDeck();
    newGame->shuffleDeck();

    //create two new cards for two new players
    Card playerCard;
    Card computerCard;

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int nWin = 0, nLoss = 0;
    srand(time(NULL));

    play = true;
    while (play) {
        // assign values to computer and player
        playerCard = newGame->removeCard();
        computerCard = newGame->removeCard();

        // get user's bet
        cout << "Computer's value is " << computerCard.yourCardIs() << endl;
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

        cout << "\tyour value is " << playerCard.yourCardIs() << endl;

        // ask user to play again
        invalid = true;
        while (invalid) {
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
            //check to see if there are cards left before looping again
            if (newGame->getNumCardsLeft() == 0) {
                play = false;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << " (W-L)" << endl;

    return 0;
}