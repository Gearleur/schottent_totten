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

    std::string Traitre::getCardInfo() const {
        return "Traitre";
    }

    void ChasseurdeTete::showCard() const {
        std::cout << "Chasseur de Tête" << std::endl;
    }

    std::string ChasseurdeTete::getCardInfo() const {
        return "Chasseur de Tête";
    }

    void Stratege::showCard() const {
        std::cout << "Stratège" << std::endl;
    }

    std::string Stratege::getCardInfo() const {
        return "Stratège";
    }

    void Banshee::showCard() const {
        std::cout << "Banshee" << std::endl;
    }

    std::string Banshee::getCardInfo() const {
        return "Banshee";
    }

}