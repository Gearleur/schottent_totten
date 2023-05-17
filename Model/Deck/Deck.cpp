//
// Created by alexa on 15/05/2023.
//

#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck() {
    this->deck = std::vector<Card *>();
}

Deck::~Deck() {
    for (int i = 0; i < this->deck.size(); i++) {
        delete this->deck[i];
    }
}

void Deck::shuffle() {
    std::random_shuffle(this->deck.begin(), this->deck.end());
}

Card * Deck::draw() {
    Card * card = this->deck.back();
    this->deck.pop_back();
    return card;
}

bool Deck::isEmpty() const {
    if (this->deck.empty()) {
        std::cout << "The deck is empty" << std::endl;
    }
}

void Deck::putBack(Card *card) {
    this->deck.push_back(card);
}

