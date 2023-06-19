//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_CLAN_H
#define SCHOTTENT_TOTTEN_CLAN_H
#include "../Card.h"

namespace Model{
    class Clan : public Card{
    public:
        friend class ClanDeck;
        Clan(Numbered number, Color color): Card(number, color, Type(0), "","",nullptr){};
        ~Clan() override = default;

        void showCard() const override;
        std::string getNom() const override {return "Clan";};
        std::string getCardInfo() const override;
    };
}


#endif //SCHOTTENT_TOTTEN_CLAN_H