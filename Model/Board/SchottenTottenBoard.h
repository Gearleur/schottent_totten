#pragma once

#include "Board.h"

namespace Model
{
    class SchottenTottenBoard : public Board
    {
    private:
        static DiscardDeck *discardDeck;
        static ClanDeck *clanDeck;
        static TacticDeck *tacticDeck;
        static SchottenTottenBoard *instance;

    public:
        static SchottenTottenBoard *getInstance()
        {
            if (instance == nullptr)
                instance = new SchottenTottenBoard();
            return instance;
        }
        static DiscardDeck *getDiscardDeck() { return discardDeck; }
        static ClanDeck *getClanDeck() { return clanDeck; }
        static TacticDeck *getTacticDeck() { return tacticDeck; }
        void createClanDeck() override;
        void createTacticDeck() override;
        void createDiscardDeck() override;
        ~SchottenTottenBoard() = default;
    };
}