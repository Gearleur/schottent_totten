#pragma once

#include "Board.h"

namespace Model
{
    class SchottenTottenBoard : public Board
    {
    private:
         DiscardDeck *discardDeck=nullptr;
         ClanDeck *clanDeck=nullptr;
         TacticDeck *tacticDeck=nullptr;
        static SchottenTottenBoard *instance;
        SchottenTottenBoard() = default;

    public:
        static SchottenTottenBoard *getInstance()
        {
            if (instance == nullptr)
                instance = new SchottenTottenBoard();
            return instance;
        }
         DiscardDeck *getDiscardDeck() override { return discardDeck; }
         ClanDeck *getClanDeck() override { return clanDeck; }
        TacticDeck *getTacticDeck() override { return tacticDeck; }
        void createClanDeck() override;
        void createTacticDeck() override;
        void createDiscardDeck() override;
        ~SchottenTottenBoard() = default;
    };
}