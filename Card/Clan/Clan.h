//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_CLAN_H
#define SCHOTTENT_TOTTEN_CLAN_H
#include "../Card.h"

class Clan: public Card{
public:
    Clan(Numbered numbered, Color color, Type Numbered): Card(number, color, Numbered, nullptr, nullptr, nullptr){};
};


#endif //SCHOTTENT_TOTTEN_CLAN_H