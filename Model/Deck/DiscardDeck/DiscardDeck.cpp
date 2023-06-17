//
// Created by leeyu on 22/05/2023.
//

#include "DiscardDeck.h"
namespace Model
{
    DiscardDeck *DiscardDeck::Instance_discardDeck = nullptr;
    void DiscardDeck::fillDeck()    //à implémenter quand je le joueur joue une carte tactique
    {
    }

    DiscardDeck::DiscardDeck() : Deck()
    {
        std::cout <<"***** DiscardDeck CONSTRUCTOR *****" <<std::endl;
    }

    void DiscardDeck::freeInstance() {
        delete Instance_discardDeck;
        Instance_discardDeck = nullptr;
    }
    void DiscardDeck::addCard(Card *card)
    {
        getDeck().push_back(card);
    }
}