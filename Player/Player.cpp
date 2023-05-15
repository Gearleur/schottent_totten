//
// Created by alexa on 15/05/2023.
//

#include "Player.h"
using namespace std;

int Player::idCounter = 0;

void Player::addCard(const Card& card) {
    if (hand.size() < 6) {
        hand.push_back(card);
    }
}

void Player::removeCard(const Card& card) {
    for (int i = 0; i < hand.size(); ++i) {
        if (hand[i].getName() == card.getName()) {
            hand.erase(hand.begin() + i);
            break;
        }
    }
}

void Player::removeCard(const int& index) {
    hand.erase(hand.begin() + index);
}

void Player::printHand() const {
    for (int i = 0; i < hand.size(); ++i) {
        cout << i << " : " << hand[i].getName() << endl;
    }
}