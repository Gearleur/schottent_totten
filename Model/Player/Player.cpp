//
// Created by alexa on 15/05/2023.
//

#include <iostream>
#include "Player.h"
using namespace std;

int Player::idCounter = 0;

//Si la carte est une carte clan: on affiche son Numéro de carte, sa couleur et son type
//Si la carte est une carte action: on affiche son Numéro de carte, sa couleur, son type et son effet
void Player::showHand() const {
    cout << "Player " << id << " hand: ";
    for (auto & i : hand) {
        cout << i->getNumber()<< " " << i->getColor() << " " << i->getType();
        if (i->getType() == 1) {
            cout << " " << i->getName();
        }
        cout << " | ";
    }
    cout << endl;
}



