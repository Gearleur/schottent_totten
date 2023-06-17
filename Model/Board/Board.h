//
// Created by alexa on 15/05/2023.
//

#pragma once

#include "../Deck/Deck.h"
#include "../Border/Border.h"
#include "../Deck/ClanDeck/ClanDeck.h"
#include "../Deck/TacticDeck/TacticDeck.h"
#include "../Deck/DiscardDeck/DiscardDeck.h"
#include "../EventManager/EventManager.h"
#include <vector>

namespace Model
{
    class Board : public Observer
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
        void update(const std::string& event) override{
            if(event == "Revendiquer") {

            }
        }

        // Destructor
        ~Board() = default;

        // Getters
        int getCompteur() const { return compteur; }

        // Method declarations
        /*virtual void createClanDeck() = 0;
        virtual void createTacticDeck() = 0;
        virtual void createDiscardDeck() = 0;*/
    };
}