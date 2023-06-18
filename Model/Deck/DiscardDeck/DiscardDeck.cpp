//
// Created by leeyu on 22/05/2023.
//

#include "DiscardDeck.h"
namespace Model
{
    DiscardDeck *DiscardDeck::Instance_discardDeck = nullptr;
    void DiscardDeck::fillDeck()
    {
    }

    DiscardDeck::DiscardDeck()
    {
        fillDeck();
    }

    void DiscardDeck::addCard(Card *card)
    {
        getDeck().push_back(card);
    }
}