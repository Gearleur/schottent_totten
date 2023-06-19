//
// Created by leeyu on 26/05/2023.
//
#include "Ruse.h"
#include "../../Card.h"
#include <iostream>

namespace Model {
    void Traitre::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Traitre"<<") "<< "\033[0m";
    }

    std::string Traitre::getCardInfo() const {
        return "Traitre";
    }

    void ChasseurdeTete::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Chasseur de Tête"<<") "<< "\033[0m";
    }

    std::string ChasseurdeTete::getCardInfo() const {
        return "Chasseur de Tête";
    }

    void Stratege::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Stratège"<<") "<< "\033[0m";
    }

    std::string Stratege::getCardInfo() const {
        return "Stratège";
    }

    void Banshee::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Banshee"<<") "<< "\033[0m";
    }

    std::string Banshee::getCardInfo() const {
        return "Banshee";
    }

}