#pragma once

#ifndef DECK_H
#define DECK_H

#include <vector>

enum class Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum class Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
};

struct Card {
    Suit suit;
    Rank rank;
};

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card drawCard();
};

#endif // DECK_H