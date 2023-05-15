//
// Created by alexa on 15/05/2023.
//

#include "Card.h"
#include "../Utils/enums.h"
#include "../Player/Player.h"

Card::Card(Numbered number, Color color, Type type, char* name, char* description, Player* owner, Effect effect):
        number(number), color(color), type(type), name(name), description(description), owner(owner), effect(effect) {};

