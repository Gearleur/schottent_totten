//
// Created by alexa on 15/05/2023.
//

#pragma once

#include "../Player.h"

namespace Model {

    class Human : public Player {
    private:
        friend class PlayerControllerFactory;
    public:
        //constructeur Human avec un nom et une main et un vector borders vide par défaut qui se base de la construction de Player
        Human(const std::string &name, const std::vector<Card *> &hand, const std::vector<Border *> &borders = std::vector<Border *>()) : Player(name, hand, borders) {};
        bool isAI() const override { return false; };
    };
}
