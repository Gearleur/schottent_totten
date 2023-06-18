//
// Created by leeyu on 22/05/2023.
//

#include "TacticDeck.h"
#include "../../Card/Tactic/CombatMode/CombatMode.h"
#include "../../Card/Tactic/EliteTroop/EliteTroop.h"
#include "../../Card/Tactic/Ruse/Ruse.h"

namespace Model
{
    TacticDeck *TacticDeck::Instance_tacticDeck = nullptr;
    void TacticDeck::fillDeck()
    {
        putBack(new Combatdeboue());
        putBack(new CollinMaillard());
        putBack(new Joker());
        putBack(new Joker());
        putBack(new Espion());
        putBack(new Portebouclier());
        putBack(new Traitre());
        putBack(new ChasseurdeTete());
        putBack(new Stratege());
        putBack(new Banshee());
    }

    TacticDeck::TacticDeck() : Deck()
    {

    }

    void TacticDeck::addCard(Card *card)
    {
        getDeck().push_back(card);
    }
}