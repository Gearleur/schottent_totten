//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_DECK_H
#define SCHOTTENT_TOTTEN_DECK_H

#include <vector>
#include "../Card/Clan/Clan.h"
;
class Clan;


//cette classe est un singleton
//elle contient toutes les cartes clan du jeu (9 cartes par couleur)
//ou toutes les cartes tactique du jeu
//la création du deck ce fait par la classe Game
//on peut vérifier si le deck est vide
//on peut piocher une carte dans le deck
//on peut mélanger le deck
//on peut remettre une carte dans le deck
class Deck {
    private:
        friend class Game;
        static Deck* instance;
        std::vector<Card*> deck;

        //constructeur
        Deck();
        ~Deck();

    public:
        //getters
        static Deck* getInstance() { return instance;}
        std::vector<Card*> getDeck() const { return deck; };

        //fonctions
        void shuffle();
        Card * draw();
        void putBack(Card* card);
        bool isEmpty() const;
        virtual void addCard(Card *card) = 0;
        virtual void fillDeck() = 0;
};


#endif //SCHOTTENT_TOTTEN_DECK_H
