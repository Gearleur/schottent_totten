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
#include <iostream>

namespace Model {
    class ClanDeck : public Deck {
    private:
        friend class SchottenTottenBoard;
        static ClanDeck* Instance_clanDeck;
        ClanDeck();
        void operator=(const ClanDeck&);
        ~ClanDeck() override{
            for(auto card : getInstance_clanDeck()->getDeck())
                delete card;
            std::cout << "***** ClanDeck DESTRUCTOR *****" << std::endl;
        }
    public:
        static ClanDeck* getInstance_clanDeck();
        void fillDeck() override;
        void addCard(Card *card) override;
        static void freeInstance();
    };
}


#endif //SCHOTTENT_TOTTEN_CLANDECK_H
