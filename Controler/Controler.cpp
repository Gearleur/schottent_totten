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
        if(game->getVariante() == "Tactique")
            return i <7;
        else
            return false;
    }
    int Controller::TacticCardCount(int idPlayer) const
    {
        int tactics = 0;
        for (auto it : observers[idPlayer]->getHand())
        {
            if (it->getType() == SPECIAL)
                tactics += 1;
        }
        return tactics;
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
    bool Controller::win(int idPlayer1, int idPlayer2,Board *board) const {
        if (game->getVariante() == "Classique")
        {   int point1=0;
            int point2=0;
           for (int i = 0; i < 9; i++){
               if(board->getBorders()[i]->getOwner()==observers[idPlayer1]){
                     point1++;
                }
                else if(board->getBorders()[i]->getOwner()==observers[idPlayer2]){
                     point2++;
               }
           }
              if(point1>=5){
                  game->setWinner(observers[idPlayer1]);
                return true;
              }
              else if(point2>=5){
                  game->setWinner(observers[idPlayer2]);
                return true;
              }
              else{
                return false;
              }
        }
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
    bool Controller::canClaimBorder(int idPlayer, Model::Board *pBoard, int borderPosition) const
    {
        if(pBoard->getBorders()[borderPosition]->isLeftFull() && pBoard->getBorders()[borderPosition]->isRightFull())
        {
            Combinaison *comboA = CombinaisonControllerFactory::createCombinaison(pBoard->getBorders()[borderPosition]->getLeftBorder());
            Combinaison *comboB = CombinaisonControllerFactory::createCombinaison(pBoard->getBorders()[borderPosition]->getRightBorder());
            if(idPlayer == 0)
            {std::cout<<"test"<<std::endl;
                return comboA->getPuissance() > comboB->getPuissance();}
            else
                return comboB->getPuissance() > comboA->getPuissance();
        }
        else    //flemme de faire le cas irréfutable c'est relou
            return false;
    }
}
