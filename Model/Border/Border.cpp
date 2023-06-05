//
// Created by alexa on 15/05/2023.
//

#include <stdexcept>
#include "Border.h"

namespace Model{

    Border::Border(int position, Player* owner) {
        this->position = position;
        this->maxCards = 3;
        this->currentCardsLeft = 0;
        this->currentCardsRight = 0;
        this->owner = owner;
    }

    void Border::addCardLeft(Card *card) {
        if (!this->isLeftFull()) {
            leftBorder.push_back(card);
            currentCardsLeft++;
        } else {
            throw std::invalid_argument("Border is full");
        }

    }
    void Border::addCardRight(Card *card) {
        if (!this->isRightFull()) {
            rightBorder.push_back(card);
            currentCardsRight++;
        } else {
            throw std::invalid_argument("Border is full");
        }
    }

    Border::~Border() = default;


}