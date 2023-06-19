//
// Created by leeyu on 26/05/2023.
//
#include "CombatMode.h"
#include "../../Card.h"
#include <iostream>
namespace Model {
    void Combatdeboue::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "Combatdeboue"<<") "<< "\033[0m";
    }

    std::string Combatdeboue::getCardInfo() const {
        return "Combatdeboue";
    }

    void CollinMaillard::showCard() const {
        std::cout << "\033[1;35m"<< "Type(Tactique)"<< "\033[0m";
        std::cout << "\033[1;35m"<< "  Nom(" << "CollinMaillard"<<") "<< "\033[0m";
    }

    std::string CollinMaillard::getCardInfo() const {
        return "CollinMaillard";
    }
}