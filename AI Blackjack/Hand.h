#pragma once

#include "Deck.h"
#include <vector>
#include <string>


class Hand {
private:
	std::vector<Card> cards;

public:
	void addCard(const Card& card);
	int getHandValue() const;
	void displayHand(bool showAllCards = true) const;

private:
	std::string getCardString(const Card& card) const;
};