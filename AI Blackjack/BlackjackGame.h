#pragma once

#include "Deck.h"
#include "Hand.h"

class BlackjackGame {
private:
	Deck deck;
	Hand playerHand;
	Hand dealerHand;

public:
	void playGame();

private:
	void dealInitialCards();
	void displayHands() const;
	void playerTurn();
	void dealerTurn();
	void determineWinner();

};