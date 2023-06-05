//
// Created by leeyu on 05/06/2023.
//

#ifndef SCHOTTENT_TOTTEN_SCHOTTENTOTTENBOARD_H
#define SCHOTTENT_TOTTEN_SCHOTTENTOTTENBOARD_H


#include "../Deck/TacticDeck/TacticDeck.h"
#include "../Deck/Clan Deck/ClanDeck.h"
#include "../Deck/DiscardDeck/DiscardDeck.h"
#include "../Border/Border.h"
#include "../Player/Player.h"
#include "Board.h"

namespace Model{
    class SchottenTottenBoard : public Board {
    private:
        static SchottenTottenBoard* Instance_schottenTottenBoard;
        SchottenTottenBoard();
    public:
        static SchottenTottenBoard* getInstance_schottenTottenBoard(){return Instance_schottenTottenBoard;};
        void createClanDeck() override;
        void createTacticDeck() override;
        void createDiscardDeck() override;

    };
}


#endif //SCHOTTENT_TOTTEN_SCHOTTENTOTTENBOARD_H
