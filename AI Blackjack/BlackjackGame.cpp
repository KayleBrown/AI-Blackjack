#include "BlackjackGame.h"
#include <iostream>
#include <limits>

void BlackjackGame::playGame() {
    std::cout << "Welcome to Blackjack!\n\n";

    // Shuffle the deck and deal initial cards
    deck.shuffle();
    dealInitialCards();

    // Display hands
    displayHands();

    // Player's turn
    playerTurn();

    // Dealer's turn
    dealerTurn();

    // Determine the winner
    determineWinner();
}

void BlackjackGame::dealInitialCards() {
    playerHand.addCard(deck.drawCard());
    dealerHand.addCard(deck.drawCard());
    playerHand.addCard(deck.drawCard());
    dealerHand.addCard(deck.drawCard());
}

void BlackjackGame::displayHands() const {
    std::cout << "Your hand: ";
    playerHand.displayHand();

    std::cout << "Dealer's hand: ";
    dealerHand.displayHand(false);  // Hide one card of the dealer
    std::cout << "\n";
}

void BlackjackGame::playerTurn() {
    char choice;

    while (true) {
        std::cout << "Do you want to hit (h) or stand (s)? ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Check if the input is valid
        if (choice == 'h' || choice == 'H') {
            playerHand.addCard(deck.drawCard());
            displayHands();

            if (playerHand.getHandValue() > 21) {
                std::cout << "Busted! You lose.\n";
                return;
            }
        }
        else if (choice == 's' || choice == 'S') {
            std::cout << "You chose to stand.\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 'h' or 's'.\n";
        }
    }
}

void BlackjackGame::dealerTurn() {
    std::cout << "\nDealer's turn:\n";
    dealerHand.displayHand();

    while (dealerHand.getHandValue() < 17) {
        std::cout << "Dealer hits.\n";
        dealerHand.addCard(deck.drawCard());
        dealerHand.displayHand();
    }

    if (dealerHand.getHandValue() > 21) {
        std::cout << "Dealer busted! You win.\n";
    }
    else {
        std::cout << "Dealer stands.\n";
    }
}

void BlackjackGame::determineWinner() {
    std::cout << "\nFinal hands:\n";
    std::cout << "Your hand: ";
    playerHand.displayHand();
    std::cout << "Dealer's hand: ";
    dealerHand.displayHand();

    int playerValue = playerHand.getHandValue();
    int dealerValue = dealerHand.getHandValue();

    if (playerValue > 21) {
        std::cout << "You busted! Dealer wins.\n";
    }
    else if (dealerValue > 21) {
        std::cout << "Dealer busted! You win.\n";
    }
    else if (playerValue > dealerValue) {
        std::cout << "You win!\n";
    }
    else if (playerValue < dealerValue) {
        std::cout << "Dealer wins.\n";
    }
    else {
        std::cout << "It's a tie!\n";
    }
}