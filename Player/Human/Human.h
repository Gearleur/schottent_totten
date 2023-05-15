//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_HUMAN_H
#define SCHOTTENT_TOTTEN_HUMAN_H

#pragma once

#include "../Player.h"

class Player;

class Human: public Player {
    public:
        Human(std::string name, vector<Card*> hand): Player(name, hand){};
        bool isAI() const override { return false; };
};


#endif //SCHOTTENT_TOTTEN_HUMAN_H
