//
// Created by alexa on 15/05/2023.
//

#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card = Card(static_cast<Clan>(i), static_cast<Value>(j));
            this->cards.push_back(card);
        }
    }
}
