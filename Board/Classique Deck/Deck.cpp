//
// Created by alexa on 15/05/2023.
//

#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 13; j++) {
            Clan clan= Clan(Numbered(i), Color(j));
            this->deck.push_back(&clan);
        }
    }
}

Deck::~Deck() {
    for (int i = 0; i < this->deck.size(); i++) {
        delete this->deck[i];
    }
}

void Deck::shuffle() {
    std::random_shuffle(this->deck.begin(), this->deck.end());
}

Clan * Deck::draw() {
    Clan * clan = this->deck.back();
    this->deck.pop_back();
    return clan;
}

void Deck::addCard(Clan * clan) {
    this->deck.push_back(clan);
}
