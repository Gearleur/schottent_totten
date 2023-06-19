//
// Created by leeyu on 14/06/2023.
//
#include <iostream>
#include "Vue.h"
#include "../Model/Card/Tactic/CombatMode/CombatMode.h"
#include "../Model/Card/Tactic/Ruse/Ruse.h"
#include <limits>

namespace Vue{

    int getRandomNumber(int max) {
        return rand() % (max + 1);  // +1 pour inclure le max
    }
    void handleTraitre(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller)
    {
        std::cout << "Vous avez joué Traitre" << std::endl;
        std::cout << "Choisissez une carte Clan ou Tactique du côté adverse de la frontière sur une Borne non revendiquée." << std::endl;
        std::cout << " placez-la devant une Borne non revendiquée de votre côté." << std::endl;
        std::cout << "sur une Borne non revendiquée." << std::endl;
        std::cout << "Vous voulez choisir quelle frontière?" << std::endl;
        int bordernumber;
        std::cin>>bordernumber;
        while( bordernumber <1||  bordernumber > 9) {

            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> bordernumber;
        }
        int index = 1;
        int changeline = 0;
        int cout = 0;
        if(pPlayer->getSide()=="droite"){
            for (const auto &card: pBoard->getBorders()[--bordernumber]->getLeftBorder()) {
                std::cout << "\033[1;35m" << "[ Carte " << index++ << " : " << "\033[0m";
                card->showCard();
                cout++;
                std::cout << "\033[1;35m" << "] " << "\033[0m";
                if (changeline == 1) {
                    std::cout << std::endl;
                    changeline = 0;
                } else {
                    changeline++;
                }
            }
        }
        else{
            for (const auto &card: pBoard->getBorders()[--bordernumber]->getRightBorder()) {
                std::cout << "\033[1;35m" << "[ Carte " << index++ << " : " << "\033[0m";
                card->showCard();
                cout++;
                std::cout << "\033[1;35m" << "] " << "\033[0m";
                if (changeline == 1) {
                    std::cout << std::endl;
                    changeline = 0;
                } else {
                    changeline++;
                }
            }
        }
        std::cout << "Vous voulez choisir quelle carte?" << std::endl;
        int cardnumber;
        std::cin>>cardnumber;
        while(cardnumber <1|| cardnumber > cout) {

            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> cardnumber;
        }
        std::cout << "Vous voulez placer la carte sur quelle frontière?" << std::endl;
        int bordernumber2;
        std::cin>>bordernumber2;
        while( bordernumber2 <1 ||  bordernumber2 > 9) {

            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> bordernumber2;
        }
        if(pPlayer->getSide()=="gaunche"){

            pBoard->getBorders()[--bordernumber2]->putCardLeft(pBoard->getBorders()[bordernumber]->getRightBorder()[--cardnumber]);
            pBoard->getBorders()[bordernumber]->removeCardLeft(cardnumber);
          }
          else
        {pBoard->getBorders()[--bordernumber2]->putCardRight(pBoard->getBorders()[bordernumber]->getLeftBorder()[--cardnumber]);
            pBoard->getBorders()[bordernumber]->removeCardLeft(cardnumber);
        }
    }
    void handleStratege(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller)
    {
        //choisissez une
        //carte Clan ou Tactique
        //de votre côté de la frontière
        //sur une Borne non revendiquée.
        //Placez-la face visible sur une
        //autre Borne non revendiquée ou
        //défaussez-la face visible à côté de la
        //pioche.
        std::cout << "Vous avez joué Stratège" << std::endl;
        std::cout << "Choisissez une carte Clan ou Tactique de votre côté de la frontière sur une Borne non revendiquée." << std::endl;
        std::cout << "Placez-la face visible sur une autre Borne non revendiquée ou défaussez-la face visible à côté de la pioche." << std::endl;
        std::cout << "sur une Borne non revendiquée." << std::endl;
        std::cout << "Vous voulez choisir quelle frontière?" << std::endl;
        int bordernumber;
        std::cin>>bordernumber;
        while( bordernumber <1||  bordernumber > 9) {

            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> bordernumber;
        }
        int index = 1;
        int changeline = 0;
        int cout = 0;
        if(pPlayer->getSide()=="gauche"){
        for (const auto &card: pBoard->getBorders()[--bordernumber]->getLeftBorder()) {
            std::cout << "\033[1;35m" << "[ Carte " << index++ << " : " << "\033[0m";
            card->showCard();
            cout++;
            std::cout << "\033[1;35m" << "] " << "\033[0m";
            if (changeline == 1) {
                std::cout << std::endl;
                changeline = 0;
            } else {
                changeline++;
            }
          }
        }
        else{
            for (const auto &card: pBoard->getBorders()[--bordernumber]->getRightBorder()) {
                std::cout << "\033[1;35m" << "[ Carte " << index++ << " : " << "\033[0m";
                card->showCard();
                cout++;
                std::cout << "\033[1;35m" << "] " << "\033[0m";
                if (changeline == 1) {
                    std::cout << std::endl;
                    changeline = 0;
                } else {
                    changeline++;
                }
            }
        }
        std::cout << "Vous voulez choisir quelle carte?" << std::endl;
        int cardnumber;
        std::cin>>cardnumber;
        while(cardnumber <1|| cardnumber > cout) {

            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> cardnumber;
        }
        std::cout << "Vous voulez placer la carte sur quelle frontière?" << std::endl;
        int bordernumber2;
        std::cin>>bordernumber2;
        while( bordernumber2 <1 ||  bordernumber2 > 9) {

            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> bordernumber2;
        }
        if(pPlayer->getSide()=="gauche"){
            std::cout << "test" << std::endl;
            pBoard->getBorders()[--bordernumber2]->putCardLeft(pBoard->getBorders()[bordernumber]->getLeftBorder()[--cardnumber]);
            pBoard->getBorders()[bordernumber]->removeCardLeft(cardnumber);

        }else
        {pBoard->getBorders()[--bordernumber2]->putCardRight(pBoard->getBorders()[bordernumber]->getRightBorder()[--cardnumber]);
            pBoard->getBorders()[bordernumber]->removeCardLeft(cardnumber);
        }



    }
    bool handlepioche(Model::Player *pPlayer, Model::Board *pBoard, size_t max_card) {
        if(!pBoard->getClanDeck()->getDeck().empty() && pPlayer->getHand().size() < max_card) {
            pPlayer->addCard(pBoard->getClanDeck()->draw());
            return true;
        }
        else
            return false;
    }

    bool handlepiocheTactic(Model::Player * pPlayer, Model::Board *pBoard, size_t max_card = 7){
        if(!pBoard->getTacticDeck()->getDeck().empty() && pPlayer->getHand().size() < max_card){
            pPlayer->addCard(pBoard->getTacticDeck()->draw());
            return true;
        }
        else
            return false;
    }
    void handleChasseurdeTete(Model::Player * pPlayer, Model::Board *pBoard, size_t max = 9)
    {
        std::cout<< "Vous avez joué Chasseur de Tête, vous pouvez piocher trois cartes."<<std::endl;
        for(int i = 0; i < 3; i++)
        {   std::cout<< "Vous voulez piocher une carte dana le deck de clan ou de tactique ?"<<std::endl;
            std::cout<< "1. Deck de clan"<<std::endl;
            std::cout<< "2. Deck de tactique"<<std::endl;
            int choice;
            std::cin>>choice;
            if(choice == 1)
            {
                handlepioche(pPlayer, pBoard, max);
            }
            else if(choice == 2)
            {
                handlepiocheTactic(pPlayer, pBoard);
            }
            else
            {
                std::cout<<"Vous n'avez pas choisi une option valide."<<std::endl;
                i--;
            }
        }
        int number = 0;
        int cardChoice = 0;
        do
        {std::cout << "Quelle carte voulez vous remettre dans son deck ?" << std::endl;
        int index = 1;
        int changeline = 0;
        for (const auto &card: pPlayer->getHand()) {
            std::cout << "\033[1;35m" << "[ Carte " << index++ << " : " << "\033[0m";
            card->showCard();
            std::cout << "\033[1;35m" << "] " << "\033[0m";
            if (changeline == 1) {
                std::cout << std::endl;
                changeline = 0;
            } else {
                changeline++;
            }
        }
        std::cin >> cardChoice;
       while(cardChoice <1|| cardChoice > pPlayer->getHand().size()) {

                std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                          << "\033[0m" << std::endl;
                std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                          << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> cardChoice;
            }
            if(pPlayer->getHand()[cardChoice]->getType() == NUMBERED){
                pBoard->getClanDeck()->putBack(pPlayer->getHand()[--cardChoice]);
                pPlayer->removeCard(cardChoice);
            }
            else {
                pBoard->getTacticDeck()->putBack(pPlayer->getHand()[--cardChoice]);
                pPlayer->removeCard(cardChoice);
            }
            number++;
        }while(number <3);
    }
    bool handleCollinMaillard(Model::Player *pPlayer, Model::Player *adversaire, Model::Board *pBoard, int borderPosition, Model::Controller *controller) {
        int sumA = 0;
        int sumB = 0;
        for (auto card: pBoard->getBorders()[borderPosition]->getLeftBorder())
            sumA += (int) card->getNumber();
        for (auto card: pBoard->getBorders()[borderPosition]->getRightBorder())
            sumB += (int) card->getNumber();
        if (sumA == sumB)    //dans le cas d'égalité totale, on retourne vrai pour le joueur appelant
            return true;
        return sumA > sumB;
    }
    void handleCombatdeboue(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice, Model::Controller *controller) //modifie le border
    {
        pBoard->getBorders()[borderChoice]->setBorne(pPlayer->getHand()[cardChoice]);
        pBoard->getBorders()[borderChoice]->setMaxCards(4);
        pPlayer->removeCard(cardChoice);
    }
    bool handleplaycard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice) {
        if(pBoard->getBorders()[borderChoice]->getOwner()!= nullptr){
            return false;
        }
        if(pPlayer->getSide()=="gauche") {
            if (pBoard->getBorders()[borderChoice]->isLeftFull()) {

                std::cout << "La bordure est pleine" << std::endl;
                return false;
            } else {
                pBoard->getBorders()[borderChoice]->putCardLeft(pPlayer->getHand()[cardChoice]);
                pPlayer->removeCard(cardChoice);
                return true;
            }
        }
        else {
            if (pBoard->getBorders()[borderChoice]->isRightFull()) {
                std::cout << "La bordure est pleine" << std::endl;
                return false;
            } else {
                pBoard->getBorders()[borderChoice]->putCardRight(pPlayer->getHand()[cardChoice]);
                pPlayer->removeCard(cardChoice);
                return true;
            }
        }

    }
    void handleBansheePlayer(Model::Player *pPlayer, std::vector<Model::Card*> borderSide, Model::Board *pBoard, Model::Controller *controller)
    {
        int cardChoice;
            std::cout << "Quelle carte voulez vous défausser ?" << std::endl;


            int index = 1;
            int changeline = 0;
            for (const auto &card: borderSide) {
                std::cout << "\033[1;35m" << "[ Carte " << index++ << " : " << "\033[0m";
                card->showCard();
                std::cout << "\033[1;35m" << "] " << "\033[0m";
                if (changeline == 1) {
                    std::cout << std::endl;
                    changeline = 0;
                } else {
                    changeline++;
                }
            }
        std::cin >> cardChoice;
        while(cardChoice <1 || cardChoice > borderSide.size()){
            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une carte valide : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> cardChoice;}

        pBoard->getDiscardDeck()->addCard(borderSide[--cardChoice]);
    }

    void handleBanshee(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller)    //borderSide est le côté adverse du border
    {   int borderPosition;
        std::cout << "Vous avez joué une Banshee !" << std::endl;
        std::cout << "Quelle frontière voulez vous attaquer ?" << std::endl;
        std::cin >> borderPosition;
        if(pPlayer->getSide()=="gauche" && pBoard->getBorders()[--borderPosition]->getOwner() == nullptr) {
            handleBansheePlayer(pPlayer, pBoard->getBorders()[borderPosition]->getRightBorder(), pBoard, controller);

        }
        else if(pPlayer->getSide()=="droite" && pBoard->getBorders()[--borderPosition]->getOwner() == nullptr){
            handleBansheePlayer(pPlayer, pBoard->getBorders()[borderPosition]->getLeftBorder(), pBoard, controller);
        }
    }


    bool handleplaytacticalcard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice, Model::Controller *controller) {
        if(pBoard->getBorders()[borderChoice]->getOwner()!= nullptr){
            return false;
        }
        if((controller->getDifferenceTacticalCard(pPlayer) >=1 )){
            std::cout << "Vous ne pouvez pas poser de carte Tactique tant que votre adversaire n’en pose pas une autre." << std::endl;
            return false;
        }
        else{
            if(pPlayer->getHand()[cardChoice]->getNom()== "Combatdeboue")
            {
                handleCombatdeboue(pPlayer, pBoard, cardChoice, borderChoice, controller);

                return true;

            }
            if(pPlayer->getHand()[cardChoice]->getNom()== "CollinMaillard")
            {
                pBoard->getBorders()[borderChoice]->setBorne(pPlayer->getHand()[cardChoice]);
                pBoard->getBorders()[borderChoice]->setColinMaillard(1);
                pPlayer->removeCard(cardChoice);

                return true;

            }

            if(pPlayer->getHand()[cardChoice]->getNom() == "Chasseur de Tête")
            {

                pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                pPlayer->removeCard(cardChoice);
                handleChasseurdeTete(pPlayer, pBoard);
                return true;

            }
            if(pPlayer->getHand()[cardChoice]->getNom() == "Stratège")
            {

                pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                pPlayer->removeCard(cardChoice);
                handleStratege(pPlayer, pBoard, controller);
                return true;
            }
            if(pPlayer->getHand()[cardChoice]->getNom() == "Banshee")
            {

                pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                pPlayer->removeCard(cardChoice);
                handleBanshee(pPlayer, pBoard, controller);
                return true;
            }
            if(pPlayer->getHand()[cardChoice]->getNom() == "Traitre")
            {

                pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                pPlayer->removeCard(cardChoice);
                handleTraitre(pPlayer, pBoard, controller);
                return true;
            }
            if(pPlayer->getSide()=="gauche") {
                if (pBoard->getBorders()[borderChoice]->isLeftFull()) {
                    //std::cout << "La bordure est pleine" << std::endl;
                    return false;
                } else {

                    pBoard->getBorders()[borderChoice]->putCardLeft(pPlayer->getHand()[cardChoice]);
                    pPlayer->removeCard(cardChoice);
                    return true;

                }
            }
            else {
                if (pBoard->getBorders()[borderChoice]->isRightFull()) {
                    //std::cout << "La bordure est pleine" << std::endl;
                    return false;
                } else {

                    pBoard->getBorders()[borderChoice]->putCardRight(pPlayer->getHand()[cardChoice]);
                    pPlayer->removeCard(cardChoice);
                    return true;
                }
            }
        }

    }
    void handleJoker(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller)
    {
        int numberChoice, colorChoice = 0;
        std::cout << "Quelle valeur voulez-vous affecter au Joker ?" << std::endl;
        std::cin >> numberChoice;
        while (numberChoice < 0 || numberChoice > 11) {
            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une valeur à affecter : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberChoice;
        }
        std::cout << "Quelle couleur voulez-vous affecter au Joker ?" << std::endl;
        std::cin >> numberChoice;
        while (colorChoice < 0 || colorChoice > 5) {
            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une couleur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une couleur à affecter : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> colorChoice;
        }
        card->setNumber(static_cast<Numbered>(numberChoice));
        card->setColor(static_cast<Color>(colorChoice));
    }
    void handleEspion(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller)
    {
        int numberChoice, colorChoice = 0;
        std::cout << "Quelle couleur voulez-vous affecter à l'Espion ?" << std::endl;
        std::cin >> numberChoice;
        while (colorChoice < 0 || colorChoice > 5) {
            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une couleur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une couleur à affecter : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> colorChoice;
        }
        card->setColor(static_cast<Color>(colorChoice));
    }

    void handlePorteBouclier(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller)
    {
        int numberChoice, colorChoice = 0;
        std::cout << "Quelle valeur voulez-vous affecter au PorteBouclier ?" << std::endl;
        std::cin >> numberChoice;
        while (numberChoice < 0 || numberChoice > 3) {
            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une valeur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une valeur à affecter : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberChoice;
        }
        std::cout << "Quelle couleur voulez-vous affecter au PorteBouclier ?" << std::endl;
        std::cin >> numberChoice;
        while (colorChoice < 0 || colorChoice > 5) {
            std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une couleur valide."
                      << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une couleur à affecter : " << "\033[0m"
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> colorChoice;
        }
        card->setNumber(static_cast<Numbered>(numberChoice));
        card->setColor(static_cast<Color>(colorChoice));
    }





    void setValuesTacticCards(Model::Player *pPlayer, Model::Board *pBoard, const std::vector<Model::Card*> *borderSide, int borderChoice, Model::Controller *controller)
    {
        for(auto card : *borderSide)
        {
            if(card->getNom() == "Joker")
                handleJoker(pPlayer, pBoard, card, controller);
            else if(card->getNom() == "Espion")
                handleEspion(pPlayer, pBoard, card, controller);
            else if(card->getNom() == "PorteBouclier")
                handlePorteBouclier(pPlayer, pBoard, card, controller);
        }
    }

    bool handledeclare(Model::Player *pPlayer, Model::Board *pBoard, int borderChoice, Model::Controller *controller) {
        if(pBoard->getBorders()[borderChoice]->getColinMaillard()==1){
           return handleCollinMaillard(pPlayer,controller->getPlayer()[!pPlayer->getId()],pBoard,borderChoice,controller);
        }
        if(pPlayer->getId() == 0)
            setValuesTacticCards(pPlayer, pBoard, &pBoard->getBorders()[borderChoice]->getLeftBorder(), borderChoice, controller);
        if(pPlayer->getId() == 1)
            setValuesTacticCards(pPlayer, pBoard, &pBoard->getBorders()[borderChoice]->getRightBorder(), borderChoice, controller);

        return controller->canClaimBorder(pPlayer->getId(), pBoard, borderChoice);
    }
    void show_board_normal(Model::Player *pPlayer, Model::Board *board) {
        std::cout << "\033[1;32mPlateau de jeu SchottenTotten en mode normal :\033[0m" << std::endl;
        std::cout << "\033[1;35m---------------------------\033[0m" << std::endl;
        std::vector<Model::Border*> borders = board->getBorders();
        for (const auto& border : borders) {
            border->showBorder();
        }
        std::cout << "\033[1;35m---------------------------\033[0m" << std::endl;
        std::cout << "\033[1;32m"<< "Cartes restantes dans la pioche : " << "\033[1;35m"<< board->getClanDeck()->getDeck().size() << "\033[0m"<< "\033[0m"<< std::endl;
        std::cout << "\033[1;32m"<< "Main du joueur : "<< "\033[0m"<< std::endl;
        std::cout << "\033[1;32m" << "Vous avez " << "\033[1;35m" << pPlayer->getHand().size() << "\033[0m" << "\033[1;32m" << " cartes dans votre main." << "\033[0m" << "\033[0m" << std::endl;
        int index = 1;
        int changeline = 0;
        for (const auto& card : pPlayer->getHand()) {
            std::cout<< "\033[1;35m"<< "[ Carte "<<index++<<" : "<< "\033[0m";
            card->showCard();
            std::cout<< "\033[1;35m"<< "] "<< "\033[0m";
            if(changeline == 1){
                std::cout << std::endl;
                changeline = 0;
            }
            else{
                changeline++;
            }
        }
        std::cout << std::endl<< std::endl;
        std::cout << "\033[1;32m"<< "Main de l'IA : "<< "\033[0m"<< std::endl;
        std::cout << "\033[1;35mVous ne pouvez pas voir.\033[0m" << std::endl;
        std::cout << std::endl;



    }
    void show_board_tactical(Model::Player *pPlayer, Model::Board *board) {
        std::cout << "\033[1;32mPlateau de jeu SchottenTotten en mode tactique :\033[0m" << std::endl;
        std::cout << "\033[1;35m---------------------------\033[0m" << std::endl;
        std::vector<Model::Border*> borders = board->getBorders();
        for (const auto& border : borders) {
            border->showBorderTactically();
        }
        std::cout << "\033[1;35m---------------------------\033[0m" << std::endl;
        int i = 1;
        std::cout << "\033[1;32m La défausse: \033[0m";
        for (const auto& card : board->getDiscardDeck()->getDeck()){
            std::cout << "\033[1;35m[ Carte " << i++ << " : \033[0m";
            card->showCard();
            std::cout << "\033[1;35m] \033[0m";
        }
        std::cout << std::endl;
        std::cout << "\033[1;35m---------------------------\033[0m" << std::endl;
        std::cout << "\033[1;32m"<< "Cartes restantes dans la pioche clan: " << "\033[1;35m"<< board->getClanDeck()->getDeck().size() << "\033[0m"<< "\033[0m"<< std::endl;
        std::cout << "\033[1;32m"<< "Cartes restantes dans la pioche tactique: " << "\033[1;35m"<< board->getTacticDeck()->getDeck().size() << "\033[0m"<< "\033[0m"<< std::endl;
        std::cout << "\033[1;32m"<< "Main du joueur : "<< "\033[0m"<< std::endl;
        std::cout << "\033[1;32m" << "Vous avez " << "\033[1;35m" << pPlayer->getHand().size() << "\033[0m" << "\033[1;32m" << " cartes dans votre main." << "\033[0m" << "\033[0m" << std::endl;
        int index = 1;
        int changeline = 0;
        for (const auto& card : pPlayer->getHand()) {
            std::cout<< "\033[1;35m"<< "[ Carte "<<index++<<" : "<< "\033[0m";
            card->showCard();
            std::cout<< "\033[1;35m"<< "] "<< "\033[0m";
            if(changeline == 1){
                std::cout << std::endl;
                changeline = 0;
            }
            else{
                changeline++;
            }
        }
        std::cout << std::endl<< std::endl;
        std::cout << "\033[1;32m"<< "Main de l'IA : "<< "\033[0m"<< std::endl;
        std::cout << "\033[1;35mVous ne pouvez pas voir.\033[0m" << std::endl;
        std::cout << std::endl;
    }

    void show_action_possible_normal(Model::Player *pPlayer, Model::Player *adversaire, Model::Board *board, Model::Controller *controller)
    {
        int compteur = board->getCompteur();
        int count_action = 0;
        std::string result;
        bool playcard = false;
        bool pioche = false;
        bool pass = false;
        if(board->getClanDeck()->getDeck().empty())
        {std::cout << "\033[1;31m" << "Le deck de clan est vide" << "\033[0m" << std::endl;
            count_action++;}
        while (!pass) {
            int choice;
            action:
            show_board_normal(pPlayer, board);
            std::cout << "\033[1;32m" << "Le compteur est à " << "\033[1;35m"<< compteur << "\033[0m"<< "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Votre côté est : " << "\033[1;35m"<< pPlayer->getSide() << "\033[0m"<< "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "C'est à "<< "\033[1;35m"<<pPlayer->getName()<< "\033[0m"<< "\033[1;32m"<< " de jouer" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Pour vous les actions possibles sont : " << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "1. Jouer une carte" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "2. Piocher une carte" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "3. Déclarer remporter une frontière" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "4. Abandonner" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout<<result;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une action : " << "\033[0m" << std::endl;
            std::cin >> choice;
            while (choice < 1 || choice > 5) {
                std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide." << "\033[0m"
                          << std::endl;
                std::cout << "\033[1;32m" << "Veuillez sélectionner une action : " << "\033[0m" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> choice;
            }

            switch (choice) {
                case 1:
                    if(playcard)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà joué une carte" << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous avez déjà joué une carte") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 1: Jouer une carte
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m" << std::endl;
                    int cardChoice;
                    std::cin >> cardChoice;
                    while (cardChoice < 1 || cardChoice > pPlayer->getHand().size()) {
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une carte valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m"
                                  << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> cardChoice;
                    }
                    cardChoice--;
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoice;
                    std::cin >> borderChoice;
                    while (borderChoice < 1 || borderChoice > 9) {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> borderChoice;
                    }
                    borderChoice--;
                    if (!handleplaycard(pPlayer, board, cardChoice, borderChoice)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas jouer cette carte sur cette frontière."
                                  << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas jouer cette carte sur cette frontière.") + "\033[0m"+ "\n";
                        break;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez joué la carte " << ++cardChoice << " sur la frontière "
                                  << ++borderChoice << "\033[0m" << std::endl;
                        result = "\033[1;32m" + std::string("Vous avez joué la carte ") + std::to_string(cardChoice) + std::string(" sur la frontière ") + std::to_string(borderChoice) + "\033[0m"+ "\n";
                        playcard = true;
                        count_action++;
                    }

                    break;

                case 2:
                    if(pioche)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà pioché une carte" << "\033[0m" << std::endl;
                        result= "\033[1;31m" + std::string("Vous avez déjà pioché une carte") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 2: Piocher une carte
                    if (!handlepioche(pPlayer, board, 6)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas piocher de carte." << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas piocher de carte.") + "\033[0m"+ "\n";
                        break;
                    } else { std::cout << "\033[1;32m" << "Vous avez pioché une carte." << "\033[0m" << std::endl;
                        pioche = true;
                        result = "\033[1;32m" + std::string("Vous avez pioché une carte.") + "\033[0m"+ "\n";
                        count_action++;}

                    break;

                case 3:
                    // Action 3 : Déclarer remporter une frontière
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoice2;
                    std::cin >> borderChoice2;
                    while (borderChoice2 < 1 || borderChoice2 > 9) {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> borderChoice2;
                    }
                    borderChoice2--;
                    if (!handledeclare(pPlayer, board, borderChoice2, controller)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas déclarer cette frontière." << "\033[0m"
                                  << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas déclarer cette frontière.") + "\033[0m"+ "\n";
                        break;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez déclaré la frontière " << borderChoice2 << "\033[0m"
                                  << std::endl;
                        result = "\033[1;32m" + std::string("Vous avez déclaré la frontière ") + std::to_string(borderChoice2) + "\033[0m"+ "\n";
                    }

                    break;

                case 4:
                    // Action 4: Abandonner
                    std::cout << "\033[1;32m"
                              << "Vous êtes sur le point d'abandonner. Voulez-vous vraiment abandonner ? (y/n)"
                              << "\033[0m" << std::endl;
                    char abandonChoice;
                    std::cin >> abandonChoice;
                    while (abandonChoice != 'y' && abandonChoice != 'n') {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Voulez-vous vraiment abandonner ? (y/n)" << "\033[0m"
                                  << std::endl;
                        std::cin >> abandonChoice;
                    }
                    if (abandonChoice == 'y') {
                        std::cout << "\033[1;32m" << "Vous avez abandonné. L'IA remporte la partie." << "\033[0m"
                                  << std::endl;
                        exit(0);
                    } else {
                        choice = 0;
                        goto action;
                    }
                default:
                    std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide." << "\033[0m"
                              << std::endl;
                    break;
            }
            if(count_action == 2){
                std::cout << "\033[1;32m" << "Vous avez effectué les actions necessaires. Vous voulez passer votre tour ? (y/n)" << "\033[0m" << std::endl;
                char passChoice;
                std::cin >> passChoice;
                while (passChoice != 'y' && passChoice != 'n') {
                    std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide."
                              << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Voulez-vous vraiment passer votre tour ? (y/n)" << "\033[0m"
                              << std::endl;
                    std::cin >> passChoice;
                }
                if (passChoice == 'y') {
                    std::cout << "\033[1;32m" << "Vous avez passé votre tour." << "\033[0m"
                              << std::endl;
                    pass=true;
                    break;
                } else {
                    std::cout << "\033[1;32m" << "Vous n'avez pas passé votre tour." << "\033[0m"
                              << std::endl;
                    result = "\033[1;32m" + std::string("Vous n'avez pas passé votre tour.") + "\033[0m"+ "\n";
                }
            }

        }

        for (int i = 0; i < 9; ++i) {
            if(board->getBorders()[i]->isLeftFull()&&board->getBorders()[i]->isRightFull()&&board->getBorders()[i]->getOwner()==nullptr){
                if(handledeclare(pPlayer,board,i,controller)){
                    controller->getBoard()->getBorders()[i]->setOwner(pPlayer);
                    std::cout  << "\033[1;35m"<< pPlayer->getName() << "\033[0m"<< "\033[1;32m"<<" a gagné la frontière "<< "\033[0m" << "\033[1;35m"<< ++i << "\033[0m"
                               << std::endl;
                    std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                } else
                {
                    controller->getBoard()->getBorders()[i]->setOwner(adversaire);
                    std::cout  << "\033[1;35m"<< adversaire->getName() << "\033[0m"<< "\033[1;32m"<<" a gagné la frontière "<< "\033[0m" << "\033[1;35m"<< ++i << "\033[0m"
                               << std::endl;
                    std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }

            }
        }
        std::cout<<controller->getGame()->getWinner()<<std::endl;
        if(controller->win(pPlayer,adversaire,board)){
            std::cout << "\033[1;32m" << "\033[1;35m"<<controller->getGame()->getWinner()->getName()<< "\033[0m"<<" a gagné la partie." << "\033[0m"
                      << std::endl;
            exit(0);
        }
        board->setCompteur(board->getCompteur()+1);
    }
    void AI_action_possible_normal(Model::Player *pPlayer, Model::Player *adversaire,Model::Board *board,Model::Controller *controller) {
        int compteur = board->getCompteur();
        bool playcard = false;
        // Action 1: Jouer une carte
        while (!playcard) {
            int cardChoice = getRandomNumber(pPlayer->getHand().size() - 1);
            int borderChoice = getRandomNumber(8);
            if (handleplaycard(pPlayer, board, cardChoice, borderChoice)) {
                show_board_normal(adversaire, board);
                std::cout << "\033[1;35m" << "AI" << "\033[0m" << "\033[1;32m" << " a joué la carte " << "\033[0m"
                          << "\033[1;35m" << ++cardChoice << "\033[0m" << "\033[1;32m" << " sur la frontière "
                          << "\033[0m"
                          << "\033[1;35m" << ++borderChoice << "\033[0m" << std::endl;
                playcard = true;
            }
        }
        // Action 2: Piocher une carte
        if (!board->getClanDeck()->isEmpty() &&pPlayer->getHand().size() < 6) {
            handlepioche(pPlayer, board,6);
            std::cout << "\033[1;35m" << "AI" << "\033[0m" << "\033[1;32m" << " a pioché une carte." << "\033[0m"
                      << std::endl;
        }
        for (int i = 0; i < 9; ++i) {
            if(board->getBorders()[i]->isLeftFull()&&board->getBorders()[i]->isRightFull()&&board->getBorders()[i]->getOwner()==nullptr){
                if(handledeclare(pPlayer,board,i,controller)){
                    controller->getBoard()->getBorders()[i]->setOwner(pPlayer);
                    std::cout  << "\033[1;35m"<< pPlayer->getName() << "\033[0m"<< "\033[1;32m"<<" a gagné la frontière "<< "\033[0m" << "\033[1;35m"<< ++i << "\033[0m"
                               << std::endl;
                    std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                } else
                {
                    controller->getBoard()->getBorders()[i]->setOwner(adversaire);
                    std::cout  << "\033[1;35m"<< adversaire->getName() << "\033[0m"<< "\033[1;32m"<<" a gagné la frontière "<< "\033[0m" << "\033[1;35m"<< ++i << "\033[0m"
                               << std::endl;
                    std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }

            }
        }

        if(controller->win(pPlayer,adversaire,board)){
            std::cout << "\033[1;32m" << "\033[1;35m"<<controller->getGame()->getWinner()->getName()<< "\033[0m"<<" a gagné la partie." << "\033[0m"
                      << std::endl;
            exit(0);
        }
        /*std::cout  << "\033[1;35m"<< pPlayer->getName() << "\033[0m"<< "\033[1;32m"<<" a fini le tour ."<< "\033[0m"
                   << std::endl;
        std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();*/
        board->setCompteur(board->getCompteur()+1);
    }


    void show_action_possible_tactic(Model::Player *pPlayer, Model::Player *adversaire, Model::Board *board, Model::Controller *controller)
    {
        int compteur = board->getCompteur();
        int count_action = 0;
        std::string result;
        bool playcard = false;
        bool pioche = false;
        bool pass = true;
        if(board->getClanDeck()->getDeck().empty())
        {std::cout << "\033[1;31m" << "Le deck clan est vide" << "\033[0m" << std::endl;
            count_action++;}
        if(board->getTacticDeck()->getDeck().empty())
        {std::cout << "\033[1;31m" << "Le deck tactique est vide" << "\033[0m" << std::endl;
            count_action++;}
        if(count_action==2){
            std::cout << "\033[1;31m" << "Les deux decks sont vides" << "\033[0m" << std::endl;
            count_action--;
        }
        for(auto & card:pPlayer->getHand()){
            if(card->getType()==0){
                pass = false;
            }

            if (pass){
                std::cout << "\033[1;32m" << "Vous avez effectué les actions necessaires. Vous voulez passer votre tour ? (y/n)" << "\033[0m" << std::endl;
                char passChoice;
                std::cin >> passChoice;
                while (passChoice != 'y' && passChoice != 'n') {
                    std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide."
                              << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Voulez-vous vraiment passer votre tour ? (y/n)" << "\033[0m"
                              << std::endl;
                    std::cin >> passChoice;
                }
                if (passChoice == 'y') {
                    std::cout << "\033[1;32m" << "Vous avez passé votre tour." << "\033[0m"
                              << std::endl;
                } else {
                    std::cout << "\033[1;32m" << "Vous n'avez pas passé votre tour." << "\033[0m"
                              << std::endl;
                    result = "\033[1;32m" + std::string("Vous n'avez pas passé votre tour.") + "\033[0m"+ "\n";
                    pass=false;
                }
            }
        }
        while (!pass) {
            int choice;
            action:
            show_board_tactical(pPlayer, board);
            std::cout << "\033[1;32m" << "Le compteur est à " << "\033[1;35m"<< compteur << "\033[0m"<< "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Votre côté est : " << "\033[1;35m"<< pPlayer->getSide() << "\033[0m"<< "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "C'est à "<< "\033[1;35m"<<pPlayer->getName()<< "\033[0m"<< "\033[1;32m"<< " de jouer" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Pour vous les actions possibles sont : " << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "1. Jouer une carte clan" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "2. Jouer une carte tactique" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "3. Piocher une carte clan" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "4. Piocher une carte tactique" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "5. Déclarer remporter une frontière" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "6. Abandonner" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout<<result;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une action : " << "\033[0m" << std::endl;
            std::cin >> choice;
            while (choice < 1 || choice > 7) {
                std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide." << "\033[0m"
                          << std::endl;
                std::cout << "\033[1;32m" << "Veuillez sélectionner une action : " << "\033[0m" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> choice;
            }

            switch (choice) {
                case 1:
                    if(playcard)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà joué une carte" << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous avez déjà joué une carte") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 1: Jouer une carte
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m" << std::endl;
                    int cardChoice;
                    std::cin >> cardChoice;
                    while (cardChoice < 1 || cardChoice > pPlayer->getHand().size()) {
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une carte valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m"
                                  << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> cardChoice;
                    }
                    cardChoice--;
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoice;
                    std::cin >> borderChoice;
                    while (borderChoice < 1 || borderChoice > 9) {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> borderChoice;
                    }
                    borderChoice--;
                    if (!handleplaycard(pPlayer, board, cardChoice, borderChoice)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas jouer cette carte sur cette frontière."
                                  << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas jouer cette carte sur cette frontière.") + "\033[0m"+ "\n";
                        break;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez joué la carte " << ++cardChoice << " sur la frontière "
                                  << ++borderChoice << "\033[0m" << std::endl;
                        result = "\033[1;32m" + std::string("Vous avez joué la carte ")  +"\033[0m"+ "\033[1;35m"+"Clan" +"\033[0m"+"\033[1;32m"+ std::string(" sur la frontière ")+ "\033[0m" +"\033[1;35m"+ std::to_string(borderChoice) + "\033[0m"+ "\n";
                        playcard = true;
                        count_action++;
                    }

                    break;
                case 2:
                    if(playcard)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà joué une carte  " << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous avez déjà joué une carte ") + "\033[0m"+ "\n";
                        break;
                    }
                    if(controller->getDifferenceTacticalCard(pPlayer)>=1){
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas jouer de carte tactique" << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas jouer de carte tactique") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 2: Jouer une carte tactique
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une carte tactique à jouer : " << "\033[0m" << std::endl;
                    int tacticalCardChoice;
                    std::cin >> tacticalCardChoice;
                    while (tacticalCardChoice < 1 || tacticalCardChoice > pPlayer->getHand().size()) {
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une carte valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m"
                                  << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> tacticalCardChoice;
                    }
                    tacticalCardChoice--;
                    if(pPlayer->getHand()[tacticalCardChoice]->getTypeInt()!=1)
                    {
                        std::cout << "\033[1;31m" << "Cette carte n'est pas une carte tactique." << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Cette carte n'est pas une carte tactique.") + "\033[0m"+ "\n";
                        break;
                    }
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoicetactical;
                    std::cin >> borderChoicetactical;
                    while (borderChoicetactical < 1 || borderChoicetactical > 9) {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> borderChoicetactical;
                    }
                    borderChoicetactical--;
                    if (!handleplaytacticalcard(pPlayer, board, tacticalCardChoice, borderChoicetactical, controller)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas jouer cette carte tactique sur cette frontière."
                                  << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas jouer cette carte tactique sur cette frontière.") + "\033[0m"+ "\n";
                        break;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez joué la carte tactique " << ++tacticalCardChoice << " sur la frontière "
                                  << ++borderChoicetactical << "\033[0m" << std::endl;
                        result = "\033[1;32m" + std::string("Vous avez joué la carte ")  +"\033[0m"+ "\033[1;35m"+"Tactique" +"\033[0m"+"\033[1;32m"+ std::string(" sur la frontière ")+ "\033[0m" +"\033[1;35m"+ std::to_string(borderChoicetactical) + "\033[0m"+ "\n";
                        playcard= true;
                        count_action++;
                        pPlayer->incrementTacticalCardPlayed();
                    }
                    break;

                case 3:
                    if(pioche)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà pioché une carte clan" << "\033[0m" << std::endl;
                        result= "\033[1;31m" + std::string("Vous avez déjà pioché une carte clan") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 2: Piocher une carte
                    if (!handlepioche(pPlayer, board, 7)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas piocher de carte clan." << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas piocher de carte clan.") + "\033[0m"+ "\n";
                        break;
                    } else { std::cout << "\033[1;32m" << "Vous avez pioché une carte clan." << "\033[0m" << std::endl;
                        pioche = true;
                        result = "\033[1;32m" + std::string("Vous avez pioché une carte clan.") + "\033[0m"+ "\n";
                        count_action++;}

                    break;
                case 4:
                    if(pioche)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà pioché une carte tactique" << "\033[0m" << std::endl;
                        result= "\033[1;31m" + std::string("Vous avez déjà pioché une carte tactique") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 2: Piocher une carte
                    if (!handlepiocheTactic(pPlayer, board)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas piocher de carte tactique." << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas piocher de carte tactique.") + "\033[0m"+ "\n";
                        break;
                    } else { std::cout << "\033[1;32m" << "Vous avez pioché une carte tactique." << "\033[0m" << std::endl;
                        pioche = true;
                        result = "\033[1;32m" + std::string("Vous avez pioché une carte tactique.") + "\033[0m"+ "\n";
                        count_action++;}

                    break;
                case 5:
                    // Action 3 : Déclarer remporter une frontière
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoice2;
                    std::cin >> borderChoice2;
                    while (borderChoice2 < 1 || borderChoice2 > 9) {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> borderChoice2;
                    }
                    borderChoice2--;
                    if (!handledeclare(pPlayer, board, borderChoice2, controller)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas déclarer cette frontière." << "\033[0m"
                                  << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas déclarer cette frontière.") + "\033[0m"+ "\n";
                        break;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez déclaré la frontière " << ++borderChoice2 << "\033[0m"
                                  << std::endl;
                        result = "\033[1;32m" + std::string("Vous avez déclaré la frontière ") + std::to_string(borderChoice2) + "\033[0m"+ "\n";
                    }

                    break;

                case 6:
                    // Action 4: Abandonner
                    std::cout << "\033[1;32m"
                              << "Vous êtes sur le point d'abandonner. Voulez-vous vraiment abandonner ? (y/n)"
                              << "\033[0m" << std::endl;
                    char abandonChoice;
                    std::cin >> abandonChoice;
                    while (abandonChoice != 'y' && abandonChoice != 'n') {
                        std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Voulez-vous vraiment abandonner ? (y/n)" << "\033[0m"
                                  << std::endl;
                        std::cin >> abandonChoice;
                    }
                    if (abandonChoice == 'y') {
                        std::cout << "\033[1;32m" << "Vous avez abandonné. L'IA remporte la partie." << "\033[0m"
                                  << std::endl;
                        exit(0);
                    } else {
                        choice = 0;
                        goto action;
                    }
                default:
                    std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide." << "\033[0m"
                              << std::endl;
                    break;
            }
            if(count_action == 2){
                std::cout << "\033[1;32m" << "Vous avez effectué les actions necessaires. Vous voulez passer votre tour ? (y/n)" << "\033[0m" << std::endl;
                char passChoice;
                std::cin >> passChoice;
                while (passChoice != 'y' && passChoice != 'n') {
                    std::cout << "\033[1;31m" << "Choix invalide. Veuillez sélectionner une action valide."
                              << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Voulez-vous vraiment passer votre tour ? (y/n)" << "\033[0m"
                              << std::endl;
                    std::cin >> passChoice;
                }
                if (passChoice == 'y') {
                    std::cout << "\033[1;32m" << "Vous avez passé votre tour." << "\033[0m"
                              << std::endl;
                    pass=true;
                    break;
                } else {
                    std::cout << "\033[1;32m" << "Vous n'avez pas passé votre tour." << "\033[0m"
                              << std::endl;
                    result = "\033[1;32m" + std::string("Vous n'avez pas passé votre tour.") + "\033[0m"+ "\n";
                }
            }

        }

        for (int i = 0; i < 9; ++i) {
            if(board->getBorders()[i]->isLeftFull()&&board->getBorders()[i]->isRightFull()&&board->getBorders()[i]->getOwner()==nullptr){
                if(handledeclare(pPlayer,board,i,controller)){
                    controller->getBoard()->getBorders()[i]->setOwner(pPlayer);
                    std::cout  << "\033[1;35m"<< pPlayer->getName() << "\033[0m"<< "\033[1;32m"<<" a gagné la frontière "<< "\033[0m" << "\033[1;35m"<< ++i << "\033[0m"
                               << std::endl;
                    std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                } else
                {
                    controller->getBoard()->getBorders()[i]->setOwner(adversaire);
                    std::cout  << "\033[1;35m"<< adversaire->getName() << "\033[0m"<< "\033[1;32m"<<" a gagné la frontière "<< "\033[0m" << "\033[1;35m"<< ++i << "\033[0m"
                               << std::endl;
                    std::cout<< "\033[1;32m"<<"Tappez sur une touche pour continuer"<< "\033[0m"<<std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }

            }
        }
        std::cout<<controller->getGame()->getWinner()<<std::endl;
        if(controller->win(pPlayer,adversaire,board)){
            std::cout << "\033[1;32m" << "\033[1;35m"<<controller->getGame()->getWinner()->getName()<< "\033[0m"<<" a gagné la partie." << "\033[0m"
                      << std::endl;
            exit(0);
        }
        board->setCompteur(board->getCompteur()+1);
    }

void version1_normal() {
        Model::Controller *  controller=  new Model::Controller(1, "Classique");
        int choix;
    Model::Player* human = new Model::Human("", std::vector<Model::Card *>());
    Model::Player* AI = new Model::Human("", std::vector<Model::Card *>());
    controller->addPlayer(human);
    controller->addPlayer(AI);
    Model::Board *board = Model::SchottenTottenBoard::getInstance();
    board->createClanDeck();
    std::cout << "\033[1;32m"<< "Le jeu commence" << "\033[0m"<< std::endl;
    std::cout << "\033[1;35m"<< "----------------------------------------------" << "\033[0m"<< std::endl;
    std::cout << "\033[1;32m"<< "Quel est votre nom?" << "\033[0m"<< std::endl;
    std::string pname;
    std::cin >> pname;
    human->setName(pname);
    controller->getPlayer()[0]->setName(human->getName());
    controller->getPlayer()[1]->setName("AI");
    std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "Vous avez 6 cartes dans votre main" << "\033[0m" << std::endl;
    std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "Vous voulez commencer à jouer en premier ou en deuxième?" << "\033[0m"
              << std::endl;
    std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "1. "
              << "Commencer en premier(La place de la carte que vous jouez est à gauche)" << "\033[0m"
              << std::endl;
    std::cout << "\033[1;32m" << "2. "
              << "Commencer en deuxième(La place de la carte que vous jouez est à droite)" << "\033[0m"
              << std::endl;
    std::cin >> choix;
    while (choix < 1 || choix > 2) {
        std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
        std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choix;

    }
    switch (choix) {
        case 1:
            std::cout << "\033[1;32m" << "Vous avez choisi de commencer en premier" << "\033[0m" << "\n"
                      << std::endl;
            controller->getPlayer()[0]->setSide("gauche");
            controller->getPlayer()[1]->setSide("droite");
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            break;
        case 2:
            std::cout << "\033[1;32m" << "Vous avez choisi de commencer en deuxième" << "\033[0m" << "\n"
                      << std::endl;
            controller->getPlayer()[0]->setSide("droite");
            controller->getPlayer()[1]->setSide("gauche");
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            show_board_normal(controller->getPlayer()[1], board);
            break;

    }


    while (1) {
        if (controller->getPlayer()[0]->getSide() == "gauche") {
            show_action_possible_normal(human, AI, board, controller);

            AI_action_possible_normal(AI, human, board, controller);
        } else {
            AI_action_possible_normal(AI, human, board, controller);

            show_action_possible_normal(human, AI, board, controller);
        }
    }
}

void version1_tactique()
{
    Model::Controller *  controller=  new Model::Controller(1, "Tactique");
    int choix;
    Model::Player* human = new Model::Human("", std::vector<Model::Card *>());
    Model::Player* AI = new Model::Human("", std::vector<Model::Card *>());
    controller->addPlayer(human);
    controller->addPlayer(AI);
    Model::Board *board = Model::SchottenTottenBoard::getInstance();
    board->createClanDeck();
    board->createTacticDeck();
    board->createDiscardDeck();
    std::cout << "\033[1;32m"<< "Le jeu commence" << "\033[0m"<< std::endl;
    std::cout << "\033[1;35m"<< "----------------------------------------------" << "\033[0m"<< std::endl;
    std::cout << "\033[1;32m"<< "Quel est votre nom?" << "\033[0m"<< std::endl;
    std::string pname;
    std::cin >> pname;
    human->setName(pname);
    controller->getPlayer()[0]->setName(human->getName());
    controller->getPlayer()[1]->setName("AI");
    std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "Vous avez 7 cartes dans votre main" << "\033[0m" << std::endl;
    std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "Vous voulez commencer à jouer en premier ou en deuxième?" << "\033[0m"
              << std::endl;
    std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << "1. "
              << "Commencer en premier(La place de la carte que vous jouez est à gauche)" << "\033[0m"
              << std::endl;
    std::cout << "\033[1;32m" << "2. "
              << "Commencer en deuxième(La place de la carte que vous jouez est à droite)" << "\033[0m"
              << std::endl;
    std::cin >> choix;
    while (choix < 1 || choix > 2) {
        std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
        std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choix;

    }
    switch (choix) {
        case 1:
            std::cout << "\033[1;32m" << "Vous avez choisi de commencer en premier" << "\033[0m" << "\n"
                      << std::endl;
            controller->getPlayer()[0]->setSide("gauche");
            controller->getPlayer()[1]->setSide("droite");
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            break;
        case 2:
            std::cout << "\033[1;32m" << "Vous avez choisi de commencer en deuxième" << "\033[0m" << "\n"
                      << std::endl;
            controller->getPlayer()[1]->setSide("gauche");
            controller->getPlayer()[0]->setSide("droite");
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[1]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            controller->getPlayer()[0]->addCard(board->getClanDeck()->draw());
            show_board_tactical(AI, board);
            break;

    }


    while (1) {
        if (controller->getPlayer()[0]->getSide() == "gauche") {
            show_action_possible_tactic(human, AI, board, controller);

            show_action_possible_tactic(AI, human, board, controller);
        } else {
            show_action_possible_tactic(AI, human, board, controller);

            show_action_possible_tactic(human, AI, board, controller);
        }
    }
}





    void show_menu_principal() {
        int choixVersion;
        int choixVariante;
        int choix;
        std::cout << "\033[1;31m" << R"(
    ____       _           _   _               _____     _   _
 / ___|  ___| |__   ___ | |_| |_ ___ _ __   |_   _|__ | |_| |_ ___ _ __
 \___ \ / __| '_ \ / _ \| __| __/ _ \ '_ \    | |/ _ \| __| __/ _ \ '_ \
  ___) | (__| | | | (_) | |_| ||  __/ | | |   | | (_) | |_| ||  __/ | | |
 |____/ \___|_| |_|\___/ \__|\__\___|_| |_|   |_|\___/ \__|\__\___|_| |_|

)" << "\033[0m" << std::endl;

        menu_principal:
        std::cout << "\033[1;35m" << "Vous pouvez choisir une option dans le menu suivant" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "\033[1;35m"<< "1. " << "Commencer une nouvelle partie (version 1)" << "\033[0m" << std::endl;
        std::cout << "\033[1;35m"<< "2. " << "Commencer une nouvelle partie (version 2)" << "\033[0m" << std::endl;
        std::cout << "\033[1;35m"<< "3. " << "Quitter" << "\033[0m" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
        std::cin >> choixVersion;
        while (choixVersion < 1 || choixVersion > 3) {
            std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choixVersion;

        }
        switch (choixVersion) {
            case 1:
                std::cout << "\033[1;35m"<< "Vous avez choisi de commencer une nouvelle partie (version 1)" << std::endl;
                std::cout << "\033[1;35m"<< "----------------------------------------------" << std::endl;
                std::cout << "\033[1;35m"<< "1. " << "Commencer une nouvelle partie comme la mode normale" << "\033[0m" << std::endl;
                std::cout << "\033[1;35m"<< "2. " << "Commencer une nouvelle partie comme la mode tactique" << "\033[0m" << std::endl;
                std::cout << "\033[1;35m"<< "3. " << "Retour" << "\033[0m" << std::endl;
                std::cin >> choixVariante;
                while (choixVariante < 1 || choixVariante > 3) {
                    std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> choixVariante;
                }
                switch (choixVariante) {
                    case 1:
                        std::cout << "\033[1;32m" << "Vous avez choisi de commencer une nouvelle partie en mode normal" << "\033[0m"<<"\n"<< std::endl;
                        version1_normal();
                        break;
                    case 2:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de commencer une nouvelle partie en mode tactique"<< "\033[0m" <<"\n"<< std::endl;
                        version1_tactique();
                        break;
                    case 3:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de retourner au menu principal" << "\033[0m"<<"\n"<< std::endl;
                        goto menu_principal;
                    default:
                        std::cout << "Vous n'avez pas choisi une option valide" <<"\n"<< std::endl;
                        break;
                }
                break;
            case 2:
                std::cout << "\033[1;35m"<< "Vous avez choisi de commencer une nouvelle partie (version 2)" << std::endl;
                std::cout << "\033[1;35m"<< "----------------------------------------------" << std::endl;
                std::cout << "\033[1;35m"<< "1. " << "Commencer une nouvelle partie comme la mode normale" << "\033[0m" << std::endl;
                std::cout << "\033[1;35m"<< "2. " << "Commencer une nouvelle partie comme la mode tactique" << "\033[0m" << std::endl;
                std::cout << "\033[1;35m"<< "3. " << "Retour" << "\033[0m" << std::endl;
                std::cin >> choixVariante;
                while (choixVariante < 1 || choixVariante > 3) {
                    std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> choix;
                }
                switch (choixVariante) {
                    case 1:
                        std::cout << "\033[1;32m" << "Vous avez choisi de commencer une nouvelle partie comme la mode normale" << "\033[0m"<<"\n"<< std::endl;
                        break;
                    case 2:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de commencer une nouvelle partie comme la mode tactique"<< "\033[0m" <<"\n"<< std::endl;
                        break;
                    case 3:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de retourner" << "\033[0m"<<"\n"<< std::endl;
                        goto menu_principal;
                    default:
                        std::cout << "Vous n'avez pas choisi une option valide" <<"\n"<< std::endl;
                        break;
                }
                break;
            case 3:
                std::cout << "Vous avez choisi de quitter" << std::endl;
                exit(0);
            default:
                std::cout << "Vous n'avez pas choisi une option valide" << std::endl;
                break;

        }

    }

}