//
// Created by alexa on 15/05/2023.
//

#include "Clan.h"
#include "../Card.h"

#include <iostream>
#include <sstream>

//affiche les informations de la carte clan
//affiche le type de carte
//affiche le numéro de la carte
//affiche la couleur de la carte

namespace Model {
    void Clan::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Clan)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Number(" << getNumber()<<")"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Color(" <<  colorNames[getColor()]<<") "<< "\033[0m";
    }

    std::string Clan::getCardInfo() const {
        std::ostringstream oss;
        oss << "\033[1;35m" << "Type(Clan)" << "\033[0m";
        oss << "\033[1;35m" << "  Number(" << getNumber() << ")" << "\033[0m";
        oss << "\033[1;35m" << "  Color(" << colorNames[getColor()] << ") " << "\033[0m";
        return oss.str();
    }
}