//
// Created by alexa on 17/05/2023.
//

#include "ClanDeck.h"
#include "../../../Utils/enums.h"
#include "../../Card/Clan/Clan.h"

// fillDeck() function
// cette fonction permet de remplir le deck de clan
// le deck rempli contient 54 cartes
// il y a 9 cartes de chaque couleur et 6 couleurs

namespace Model
{
    ClanDeck *ClanDeck::Instance_clanDeck = nullptr;
    void ClanDeck::fillDeck()
    {
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 1; j < 10; ++j)
            {
                putBack(new Clan(static_cast<Numbered>(j), static_cast<Color>(i)));
            }
        }
    }

    ClanDeck::ClanDeck() = default;

    void ClanDeck::addCard(Card *card)
    {
        getDeck().push_back(card);
    }
}
