//
// Created by leeyu on 26/05/2023.
//
#include "CombatMode.h"
#include "../../Card.h"
#include <iostream>
namespace Model {
    void Combatdeboue::showCard() const {
        std::cout << "Combatdeboue" << std::endl;
    }

    std::string Combatdeboue::getCardInfo() const {
        return "Combatdeboue";
    }

    void CollinMaillard::showCard() const {
        std::cout << "CollinMaillard" << std::endl;
    }

    std::string CollinMaillard::getCardInfo() const {
        return "CollinMaillard";
    }
}