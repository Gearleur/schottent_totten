//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_HUMAN_H
#define SCHOTTENT_TOTTEN_HUMAN_H

#pragma once

#include "../Player.h"

class Player;
class Border;


class Human: public Player {
    public:
    //constructeur Human avec un nom et une main et un vector borders vide par défaut
    Human(const std::string& name, const std::vector<Card*>& hand, const std::vector<Border*>& borders = std::vector<Border*>()): Player(name, hand, borders){};
        bool isAI() const override { return false; };
};


#endif //SCHOTTENT_TOTTEN_HUMAN_H