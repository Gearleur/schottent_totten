//
// Created by leeyu on 26/05/2023.
//
#include "Ruse.h"
#include "../../Card.h"
#include <iostream>

namespace Model {
    void Traitre::showCard() const {
        std::cout << "Traitre" << std::endl;
    }

    void ChasseurdeTete::showCard() const {
        std::cout << "Chasseur de Tête" << std::endl;
    }

    void Stratege::showCard() const {
        std::cout << "Stratège" << std::endl;
    }

    void Banshee::showCard() const {
        std::cout << "Banshee" << std::endl;
    }

}