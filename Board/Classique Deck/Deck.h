//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_DECK_H
#define SCHOTTENT_TOTTEN_DECK_H

#include <vector>
#include "../../Card/Clan/Clan.h"
;
class Clan;


//cette classe est un singleton
//elle contient toutes les cartes clan du jeu (9 cartes par couleur)
//la création du deck ce fait par la classe Game
//on peut vérifier si le deck est vide
//on peut piocher une carte dans le deck
//on peut mélanger le deck
//on peut remettre une carte dans le deck
class Deck {
    private:
        friend class Game;
        static Deck* instance;
        vector<Clan*> deck;

        Deck();
        ~Deck();

    public:
        //getters
        static Deck* getInstance();
        vector<Clan*> getDeck() const { return deck; };

        //fonctions
        void shuffle();
        Clan * draw();
        void putBack(Clan* clan);
        void isEmpty() const;
        void addCard(Clan *clan);
};


#endif //SCHOTTENT_TOTTEN_DECK_H
