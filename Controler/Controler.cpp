#include "Controler.h"

namespace Model
{
    bool Controller::canDrawClanCard(int idPlayer) const
    {
        size_t i = 0;
        for (auto it : observers[idPlayer]->getHand())
            i++;
        if (game->getVariante() == "Classique")
            return i < 6;
        else
            return false;
    }
    int Controller::TacticCardCount(int idPlayer) const
    {
        if (game->getVariante() == "Tactique")
        {
            int tactics = 0;
            for (auto it : observers[idPlayer]->getHand())
            {
                if (it->getType() == SPECIAL)
                    tactics += 1;
            }
            return tactics;
        }
        else
            return 0;
    }
    bool Controller::canDrawTactic(int idPlayer) const
    {
        if (game->getVariante() == "Tactique")
        {
            int tactics = TacticCardCount(idPlayer);
            if (tactics == 1)
                return false;
            else
                return true;
        }
        else
            return false;
    }
    bool Controller::canPlayCard(int idPlayer, int borderPosition) const  //on peut la découper en 2 méthodes right et left
    {
        if (idPlayer == 0) // C'est le joueur à gauche du border
        {
            if (borders[borderPosition]->isLeftFull()) {
                if (std::any_of(observers[idPlayer]->getHand().begin(), observers[idPlayer]->getHand().end(), [](const auto& card) {
                    return card->getName() == "Combat de Boue";
                })) {
                    borders[borderPosition]->setMaxCards(4);
                    return true;
                }
                return false;
            }
            else {
                return true;
            }
        }
        else // C'est le joueur à droite du border
        {
            if (borders[borderPosition]->isRightFull()) {
                if (std::any_of(observers[idPlayer]->getHand().begin(), observers[idPlayer]->getHand().end(), [](const auto& card) {
                    return card->getName() == "Combat de Boue";
                })) {
                    borders[borderPosition]->setMaxCards(4);
                    return true;
                }
                return false;
            }
            else
                return true;
        }
    }
    bool Controller::canClaimBorder(int idPlayer, int borderPosition) const
    {
        if(borders[borderPosition]->isLeftFull() && borders[borderPosition]->isRightFull()) //on peut plus poser de carte des deux côtés
        {
            Combinaison *comboA = CombinaisonControllerFactory::createCombinaison(borders[borderPosition]->getLeftBorder());
            Combinaison *comboB = CombinaisonControllerFactory::createCombinaison(borders[borderPosition]->getRightBorder());
            if(idPlayer == 0)
                return comboA->getPuissance() > comboB->getPuissance();
            else
                return comboB->getPuissance() > comboA->getPuissance();
        }
        else    //flemme de faire le cas irréfutable c'est relou
            return false;
    }
}
