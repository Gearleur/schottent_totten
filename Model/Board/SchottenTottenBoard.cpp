// SchottenTottenBoard.cpp

#include "SchottenTottenBoard.h"
#include "../Deck/ClanDeck/ClanDeck.h"
#include "../Deck/TacticDeck/TacticDeck.h"
#include "../Deck/DiscardDeck/DiscardDeck.h"

namespace Model
{

    SchottenTottenBoard *SchottenTottenBoard::instance = nullptr;

    void SchottenTottenBoard::createClanDeck()
    {
        if (clanDeck == nullptr)
        {
            clanDeck = ClanDeck::getInstance_clanDeck();
            clanDeck->fillDeck();
            clanDeck->shuffle();
        }
    }

    void SchottenTottenBoard::createTacticDeck()
    {
        if (tacticDeck == nullptr)
        {
            tacticDeck = TacticDeck::getInstance_tacticDeck();
            tacticDeck->fillDeck();
            tacticDeck->shuffle();
        }
    }

    void SchottenTottenBoard::createDiscardDeck()
    {
        if (discardDeck == nullptr)
            discardDeck = DiscardDeck::getInstance_discardDeck();
    }
}
