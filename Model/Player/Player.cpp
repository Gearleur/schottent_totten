//
// Created by alexa on 15/05/2023.
//

#include <iostream>
#include "Player.h"
namespace Model {
    int Player::idCounter = 0;

//Si la carte est une carte clan: on affiche son Numéro de carte, sa couleur et son type
//Si la carte est une carte action: on affiche son Numéro de carte, sa couleur, son type et son effet
    void Player::showHand() const {
        std::cout << "Player " << id << " hand: ";
        for (auto &i: hand) {
            std::cout << i->getNumber() << " " << i->getColor() << " " << i->getType();
            if (i->getType() == 1) {
                std::cout << " " << i->getNom();
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
    }

    /*void Player::update(const std::string &event) {
            if(event == "Piocher carte Tactique") {

            }
            if(event == "Piocher carte Clan") {

            }
    }*/
}



