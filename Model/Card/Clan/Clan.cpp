//
// Created by alexa on 15/05/2023.
//

#include "Clan.h"
#include "../Card.h"

#include <iostream>

//affiche les informations de la carte clan
//affiche le type de carte
//affiche le numéro de la carte
//affiche la couleur de la carte

namespace Model {
    void Clan::showCard() const {
        std::cout << "Type : " << getType() << std::endl;
        std::cout << "Number : " << getNumber() << std::endl;
        std::cout << "Color : " << getColor() << std::endl;
    }
    Clan::~Clan() {
            std::cout<< "***** CLAN CARD DESTRUCTOR *****"<< std::endl;
    }
}