#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck(){
    for (int s = 0; s < 4; ++s) {
        for (int r = 0; r < 13; ++r) {
            cards.push_back({ static_cast<Suit>(s), static_cast<Rank>(r) });
        }
    }
}

void Deck::shuffle() {
    std::srand(std::time(0));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}