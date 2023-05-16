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

void Deck::addCard(Card * card) {
    this->deck.push_back(card);
}

//rempli le deck de carte de clan
//chaque carte est unique
//il y a 9 cartes par couleur
void Deck::fillClanDeck() {
    if (this->deck.size() != 0) {
        std::cout << "Deck is not empty" << std::endl;
        return;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++)
            this->addCard(new Clan(Numbered(i), Color(j)));
    }
}

