//
// Created by leeyu on 26/05/2023.
//
#include "EliteTroop.h"
#include "../../Card.h"
#include <iostream>
namespace Model {
    void Joker::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "joker"<<") "<< "\033[0m";
    }

    std::string Joker::getCardInfo() const {
        return "joker";
    }

    void Espion::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Espion"<<") "<< "\033[0m";
    }

    std::string Espion::getCardInfo() const {
        return "Espion";
    }

    void Portebouclier::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Porte bouclier"<<") "<< "\033[0m";
    }
    void Portebouclier::choseNumber(Numbered number) {
        if(number == ONE || number == TWO || number == THREE){
            this->number = number;
        }
        else{
            std::cout << "Invalid number" << std::endl;
        }
    }

    std::string Portebouclier::getCardInfo() const {
        return "Portebouclier";
    }


}