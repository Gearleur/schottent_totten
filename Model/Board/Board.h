//
// Created by alexa on 15/05/2023.
//

#pragma once

#include "../Deck/Deck.h"
#include "../Border/Border.h"
#include "../Deck/ClanDeck/ClanDeck.h"
#include "../Deck/TacticDeck/TacticDeck.h"
#include "../Deck/DiscardDeck/DiscardDeck.h"
#include <vector>

namespace Model
{
    class Board
    {
    protected:
        friend class Game;
        friend class Controller;
        friend class Border;
        int compteur;
        std::vector<Border *> borders;
        /*EventManager events;*/
    public:
        // Constructor
        Board() : compteur(0), borders(std::vector<Border *>())
        {
            for (int i = 0; i < 9; i++)
            {
                borders.push_back(new Border(i, nullptr));
            }
        };

        // Destructor
        ~Board() = default;

        // Getters
        int getCompteur() const { return compteur; }
        void setCompteur(int compteur) { this->compteur = compteur; }
        std::vector<Border *> getBorders() const { return borders; }



        // Method declarations
        virtual void createClanDeck() = 0;
        virtual void createTacticDeck() = 0;
        virtual void createDiscardDeck() = 0;
        virtual  DiscardDeck *getDiscardDeck() = 0;
        virtual  ClanDeck *getClanDeck() = 0;
        virtual  TacticDeck *getTacticDeck() = 0;
    };
}