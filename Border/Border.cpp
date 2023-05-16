//
// Created by alexa on 15/05/2023.
//

#include "Border.h"

Border::Border(int position, Player* owner) {
    this->position = position;
    this->maxCards = 3;
    this->currentCardsLeft = 0;
    this->currentCardsRight = 0;
    this->owner = owner;
}

void Border::addCard(Card* card, vector<Card*> border) {
    if(!this->isFull(border)) {
        border.push_back(card);
    }
}

bool Border::isFull(vector<Card*> border) {
    return border.size() == this->maxCards;
}

bool Border::isEmpty(vector<Card*> border) {
    return border.size() == 0;
}