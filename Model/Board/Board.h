//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_BOARD_H
#define SCHOTTENT_TOTTEN_BOARD_H

#include "../Deck/Clan Deck/ClanDeck.h"
#include "../Deck/TacticDeck/TacticDeck.h"
#include "../Deck/DiscardDeck/DiscardDeck.h"
#include "../Border/Border.h"
#include <vector>

namespace Model{
    class Board {
    protected:
        int compteur;
        DiscardDeck* discardDeck;
        ClanDeck* clanDeck;
        TacticDeck* tacticDeck;
        std::vector<Border*> borders;
        /*EventManager events;*/

    public:
        // Constructor
        Board();

        // Destructor
         ~Board() {
            delete clanDeck;
            delete tacticDeck;
            delete discardDeck;
        }

        // Getters
        int getCompteur() const { return compteur; }
        DiscardDeck* getDefausse() const { return discardDeck; }
        ClanDeck* getClanDeck() const { return clanDeck; }
        TacticDeck* getTacticDeck() const { return tacticDeck; }

        // Method declarations
         virtual void createClanDeck()=0;
         virtual void createTacticDeck()=0;
         virtual void createDiscardDeck()=0;
    };
}


#endif //SCHOTTENT_TOTTEN_BOARD_H
