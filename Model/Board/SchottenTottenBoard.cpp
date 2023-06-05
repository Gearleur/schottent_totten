//
// Created by leeyu on 05/06/2023.
//

#include "SchottenTottenBoard.h"
namespace Model {
    static SchottenTottenBoard* Instance_schottenTottenBoard = nullptr;
    void SchottenTottenBoard::createClanDeck() {
        this->clanDeck = ClanDeck::getInstance_clanDeck();
        this->clanDeck->fillDeck();
        this->clanDeck->shuffle();
    }
    void SchottenTottenBoard::createTacticDeck() {
        this->tacticDeck = TacticDeck::getInstance_tacticDeck();
        this->tacticDeck->fillDeck();
        this->tacticDeck->shuffle();
    }
    void SchottenTottenBoard::createDiscardDeck() {
        this->discardDeck = DiscardDeck::getInstance_discardDeck();
    }

    SchottenTottenBoard::SchottenTottenBoard() {
        this->compteur = 0;
        this->createClanDeck();
        this->createTacticDeck();
        this->createDiscardDeck();
        this->borders = std::vector<Border*>();
        for (int i = 0; i < 9; i++) {
            this->borders.push_back(new Border(i, nullptr));
        }

    }


}

