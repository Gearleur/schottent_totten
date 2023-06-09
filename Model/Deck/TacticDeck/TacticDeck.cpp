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
        getDeck().push_back(new Combatdeboue());
        getDeck().push_back(new CollinMaillard());
        getDeck().push_back(new Joker());
        getDeck().push_back(new Joker());
        getDeck().push_back(new Espion());
        getDeck().push_back(new Portebouclier());
        getDeck().push_back(new Traitre());
        getDeck().push_back(new ChasseurdeTete());
        getDeck().push_back(new Stratege());
        getDeck().push_back(new Banshee());
    }

    TacticDeck::TacticDeck()
    {
        fillDeck();
    }

    void TacticDeck::addCard(Card *card)
    {
        getDeck().push_back(card);
    }
}