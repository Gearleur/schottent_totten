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
    void Espion::showCard() const {
        std::cout<<"Espion"<<std::endl;
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


}