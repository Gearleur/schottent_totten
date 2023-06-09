//
// Created by alexa on 17/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_CLANDECK_H
#define SCHOTTENT_TOTTEN_CLANDECK_H

//cette class herite de la classe deck et permet de creer un deck de clan
//un deck clan est un deck contenant toutes les cartes clan
//il y a 9 cartes de chaque couleur et 6 couleurs
//donc un deck de clan contient 54 cartes
//on doit impplémenter une fonction qui permet remplir le deck de clan

#include "../Deck.h"

namespace Model {
    class ClanDeck : public Deck {
    private:
        static ClanDeck* Instance_clanDeck;
        ClanDeck();
    public:
        static ClanDeck* getInstance_clanDeck(){
            if(Instance_clanDeck == nullptr)
                Instance_clanDeck = new ClanDeck();
            return Instance_clanDeck;};
        void addCard(Card *card) override;
        void fillDeck() override;
    };
}


#endif //SCHOTTENT_TOTTEN_CLANDECK_H
