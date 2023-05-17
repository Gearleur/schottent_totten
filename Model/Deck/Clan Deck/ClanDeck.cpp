//
// Created by alexa on 17/05/2023.
//

#include "ClanDeck.h"
#include "../../../Utils/enums.h"

//fillDeck() function
//cette fonction permet de remplir le deck de clan
//le deck rempli contient 54 cartes
//il y a 9 cartes de chaque couleur et 6 couleurs

void ClanDeck::fillDeck() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 1; j < 10; ++j) {
            getDeck().push_back(new Clan(static_cast<Numbered>(j), static_cast<Color>(i)));
        }
    }
}
