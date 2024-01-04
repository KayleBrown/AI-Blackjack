#include "Hand.h"
#include <iostream>

void Hand::addCard(const Card& card) {
    cards.push_back(card);
}

int Hand::getHandValue() const {
    int value = 0;
    int numAces = 0;

    for (const auto& card : cards) {
        if (card.rank == Rank::ACE) {
            ++numAces;
            value += 11;  // Assume ACE is 11, we'll adjust later if needed
        }
        else if (card.rank >= Rank::TEN) {
            value += 10;
        }
        else {
            value += static_cast<int>(card.rank) + 2;
        }
    }

    // Adjust value for aces
    while (value > 21 && numAces > 0) {
        value -= 10;  // Change ACE value from 11 to 1
        --numAces;
    }

    return value;
}

void Hand::displayHand(bool showAllCards) const {
    for (size_t i = 0; i < cards.size(); ++i) {
        if (!showAllCards && i == 0) {
            std::cout << "??";
        }
        else {
            std::cout << getCardString(cards[i]);
        }

        if (i < cards.size() - 1) {
            std::cout << " / ";
        }
    }

    if (showAllCards) {
        std::cout << ":(" << getHandValue() << ")\n";
    }
    else {
        std::cout << ":(?)\n";
    }
}

std::string Hand::getCardString(const Card& card) const {
    std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    std::string ranks[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                            "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

    return ranks[static_cast<int>(card.rank)] + " of " + suits[static_cast<int>(card.suit)];
}