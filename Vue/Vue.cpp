//
// Created by leeyu on 14/06/2023.
//
#include <iostream>
#include "Vue.h"

namespace Vue{

    Model::Controller *controller;
    bool handleplaycard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice) {
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

    bool handleplaytacticalcard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice) {
        if((controller->getDifferenceTacticalCard() > 1 && pPlayer->getId() == 0) ||(controller->getDifferenceTacticalCard() > 1 && pPlayer->getId() == 1)){
            std::cout << "Vous ne pouvez pas poser de carte Tactique tant que votre adversaire n’en pose pas une autre." << std::endl;
            return false;
        }
        else{
            if(pPlayer->getSide()=="gauche") {
                if (pBoard->getBorders()[borderChoice]->isLeftFull()) {

                    std::cout << "La bordure est pleine" << std::endl;
                    return false;
                } else {
                    if(pPlayer->getHand()[cardChoice]->getName() == "Chasseur de Tête")
                    {

                        pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                    }
                    if(pPlayer->getHand()[cardChoice]->getName() == "Stratège")
                    {

                        pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                    }
                    if(pPlayer->getHand()[cardChoice]->getName() == "Banshee")
                    {

                        pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                    }
                    if(pPlayer->getHand()[cardChoice]->getName() == "Traitre")
                    {

                        pBoard->getDiscardDeck()->addCard(pPlayer->getHand()[cardChoice]);
                    }

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

    }

    bool handlepioche(Model::Player *pPlayer, Model::Board *pBoard) {
        if(!pBoard->getClanDeck()->getDeck().empty()&& controller->canDrawClanCard(pPlayer->getId())) {
            pPlayer->addCard(pBoard->getClanDeck()->draw());
            return true;
        }
        else
            return false;
    }

    bool handlepiocheTactic(Model::Player * pPlayer, Model::Board *pBoard){
        if(!pBoard->getTacticDeck()->getDeck().empty() && pPlayer->getHand().size() < 7){
            pPlayer->addCard(pBoard->getTacticDeck()->draw());
            return true;
        }
        else
            return false;
    }


    void setValuesTacticCards(Model::Player *pPlayer, Model::Board *pBoard, const std::vector<Model::Card*> *borderSide, int borderChoice)
    {
        int numberChoice, colorChoice = 0;
        for(auto card : *borderSide)
        {
            if(card->getName() == "Joker") {
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
            else if(card->getName() == "Espion")
            {
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
            else if(card->getName() == "PorteBouclier")
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
    }

    bool handledeclare(Model::Player *pPlayer, Model::Board *pBoard, int borderChoice) {
        if(pPlayer->getId() == 0)
            setValuesTacticCards(pPlayer, pBoard, &pBoard->getBorders()[borderChoice]->getLeftBorder(), borderChoice);
        if(pPlayer->getId() == 1)
            setValuesTacticCards(pPlayer, pBoard, &pBoard->getBorders()[borderChoice]->getRightBorder(), borderChoice);

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
            border->showBorder();
        }
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

    void show_action_possible_normal(Model::Player *pPlayer, Model::Board *board)
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
                    if (!handlepioche(pPlayer, board)) {
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
                    if (!handledeclare(pPlayer, board, borderChoice2)) {
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
        board->setCompteur(board->getCompteur()+1);
    }


    void show_action_possible_tactic(Model::Player *pPlayer, Model::Board *board)
    {
        int compteur = board->getCompteur();
        int count_action = 0;
        std::string result;
        bool playcard_clan = false;
        bool playcard_tactic = false;
        bool pioche_clan = false;
        bool pioche_tactic = false;
        bool pass = false;
        if(board->getClanDeck()->getDeck().empty())
        {std::cout << "\033[1;31m" << "Le deck clan est vide" << "\033[0m" << std::endl;
            count_action++;}
        if(board->getTacticDeck()->getDeck().empty())
        {std::cout << "\033[1;31m" << "Le deck tactique est vide" << "\033[0m" << std::endl;
            count_action++;}
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
                    if(playcard_clan)
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
                        playcard_clan = true;
                        count_action++;
                    }

                    break;
                case 2:
                    if(playcard_tactic)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà joué une carte tactique " << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous avez déjà joué une carte tactique") + "\033[0m"+ "\n";
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
                    if (!handleplaytacticalcard(pPlayer, board, tacticalCardChoice, borderChoicetactical)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas jouer cette carte tactique sur cette frontière."
                                  << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas jouer cette carte tactiquesur cette frontière.") + "\033[0m"+ "\n";
                        break;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez joué la carte tactique" << ++tacticalCardChoice << " sur la frontière "
                                  << ++borderChoice << "\033[0m" << std::endl;
                        result = "\033[1;32m" + std::string("Vous avez joué la carte tactique") + std::to_string(tacticalCardChoice) + std::string(" sur la frontière ") + std::to_string(borderChoicetactical) + "\033[0m"+ "\n";
                        playcard_tactic= true;
                        count_action++;
                        pPlayer->incrementTacticalCardPlayed();
                    }
                    break;

                case 3:
                    if(pioche_clan)
                    {
                        std::cout << "\033[1;31m" << "Vous avez déjà pioché une carte clan" << "\033[0m" << std::endl;
                        result= "\033[1;31m" + std::string("Vous avez déjà pioché une carte clan") + "\033[0m"+ "\n";
                        break;
                    }
                    // Action 2: Piocher une carte
                    if (!handlepioche(pPlayer, board)) {
                        std::cout << "\033[1;31m" << "Vous ne pouvez pas piocher de carte clan." << "\033[0m" << std::endl;
                        result = "\033[1;31m" + std::string("Vous ne pouvez pas piocher de carte clan.") + "\033[0m"+ "\n";
                        break;
                    } else { std::cout << "\033[1;32m" << "Vous avez pioché une carte clan." << "\033[0m" << std::endl;
                        pioche_clan = true;
                        result = "\033[1;32m" + std::string("Vous avez pioché une carte clan.") + "\033[0m"+ "\n";
                        count_action++;}

                    break;
                case 4:
                    if(pioche_tactic)
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
                        pioche_tactic = true;
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
                    if (!handledeclare(pPlayer, board, borderChoice2)) {
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
        board->setCompteur(board->getCompteur()+1);
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
                        break;
                    case 2:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de commencer une nouvelle partie en mode tactique"<< "\033[0m" <<"\n"<< std::endl;
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
        if(choixVersion == 1 && choixVariante == 1) {
            Model::Controller* controller = new Model::Controller(1, "Classique");
            Model::Player *human = new Model::Human("", std::vector<Model::Card *>());
            Model::Player *AI = new Model::Human("", std::vector<Model::Card *>());
            controller->addPlayer(human);
            controller->addPlayer(AI);
            Model::Board *board = Model::SchottenTottenBoard::getInstance();
            board->createClanDeck();
            std::cout << "\033[1;32m" << "Le jeu commence" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Quel est votre nom?" << "\033[0m" << std::endl;
            std::string pname;
            std::cin >> pname;
            human->setName(pname);
            controller->getPlayer()[0]->setName(human->getName());
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
                    human->setSide("droite");
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
                    show_action_possible_normal(controller->getPlayer(0), board);

                    show_action_possible_normal(controller->getPlayer(1), board);
                } else {
                    show_action_possible_normal(controller->getPlayer(1), board);

                    show_action_possible_normal(controller->getPlayer(0), board);
                }
            }
        }
        else if(choixVersion == 1 && choixVariante == 2){
            Model::Controller* controller = new Model::Controller(1, "Tactique");
        Model::Player *human = new Model::Human("", std::vector<Model::Card *>());
        Model::Player *AI = new Model::Human("", std::vector<Model::Card *>());
        controller->addPlayer(human);
        controller->addPlayer(AI);
        Model::Board *board = Model::SchottenTottenBoard::getInstance();
        board->createClanDeck();
        board->createTacticDeck();
        board->createDiscardDeck();
        std::cout << "\033[1;32m" << "Le jeu commence" << "\033[0m" << std::endl;
        std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
        std::cout << "\033[1;32m" << "Quel est votre nom?" << "\033[0m" << std::endl;
        std::string pname;
        std::cin >> pname;
        human->setName(pname);
        controller->getPlayer()[0]->setName(human->getName());
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
                show_action_possible_tactic(controller->getPlayer()[0], board);

                show_action_possible_tactic(controller->getPlayer()[1], board);
            } else {
                show_action_possible_tactic(controller->getPlayer()[1], board);

                show_action_possible_tactic(controller->getPlayer()[0], board);
            }
        }
    }
    }




}