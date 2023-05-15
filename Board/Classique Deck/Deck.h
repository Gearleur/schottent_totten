//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_DECK_H
#define SCHOTTENT_TOTTEN_DECK_H

#include <vector>
#include "../../Card/Clan/Clan.h"

class Card;
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
        vector<Card*> deck;

        Deck();
        ~Deck()=default;

    public:
        //getters
        static Deck* getInstance();
        vector<Card*> getDeck() const { return deck; };

        //fonctions
        void shuffle();
        Card* draw();
        void putBack(Card* card);
        void isEmpty() const;
};


#endif //SCHOTTENT_TOTTEN_DECK_H
