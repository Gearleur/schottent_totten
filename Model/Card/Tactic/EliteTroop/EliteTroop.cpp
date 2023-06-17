//
// Created by leeyu on 26/05/2023.
//
#include "EliteTroop.h"
#include "../../Card.h"
#include <iostream>
namespace Model {
    void Joker::showCard() const {
        std::cout<<"joker"<<std::endl;
    }

    std::string Joker::getCardInfo() const {
        return "joker";
    }

    void Espion::showCard() const {
        std::cout<<"Espion"<<std::endl;
    }

    std::string Espion::getCardInfo() const {
        return "Espion";
    }

    void Portebouclier::showCard() const {
        std::cout<<"Portebouclier"<<std::endl;
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