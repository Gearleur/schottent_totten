//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_CLAN_H
#define SCHOTTENT_TOTTEN_CLAN_H
#include "../Card.h"
#include <iostream>

namespace Model{
    class Clan : public Card{
    public:
        friend class ClanDeck;
        Clan(Numbered number, Color color): Card(number, color, Type(0), "","",nullptr){
            std::cout<< "***** CLAN CARD CONSTRUCTOR *****"<< std::endl;
        };
        ~Clan();

        void showCard() const override;
    };
}


#endif //SCHOTTENT_TOTTEN_CLAN_H
