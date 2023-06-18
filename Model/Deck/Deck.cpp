//
// Created by alexa on 15/05/2023.
//

#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <random>

namespace Model
{

    Deck::Deck()
    {
        this->deck = std::vector<Card *>();
    }

    Deck::~Deck()
    {
        for (int i = 0; i < this->deck.size(); i++)
        {
            delete this->deck[i];
        }
    }

    void Deck::shuffle()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(this->deck.begin(), this->deck.end(), gen);
    }

    Card *Deck::draw()
    {
        Card *card = this->deck.back();
        this->deck.pop_back();
        return card;
    }

    bool Deck::isEmpty() const
    {
        if (this->deck.empty())
        {
            std::cout << "The deck is empty" << std::endl;
        }
        return this->deck.empty();
    }

    void Deck::putBack(Card *card)
    {
        this->deck.push_back(card);
    }
}