//
// Created by leeyu on 14/06/2023.
//
#include <iostream>
#include "menu.h"
#include "../Model/Board/Board.h"
#include "../Model/Player/Player.h"
#include "../Model/Board/SchottenTottenBoard.h"
#include "../Controler/Controler.h"
#include "../Model/Card/Clan/Clan.h"

namespace Vue{


    bool handlepalycard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice) {
        return true;

    }

    bool handlepioche(Model::Player *pPlayer, Model::Board *pBoard) {
        return true;
    }

    bool handledeclare(Model::Player *pPlayer, Model::Board *pBoard) {
        return false;
    }

    void show_action_possible_normal(Model::Player *pPlayer, Model::Board *board)
    {
        int compteur = board->getCompteur();
        int count_action = 0;
        bool pass = false;
        if(board->getClanDeck()->getDeck().empty())
        {std::cout << "\033[1;31m" << "Le deck de clan est vide" << "\033[0m" << std::endl;
            count_action++;}
        while (!pass) {
            int choice;
            action:
            std::cout << "\033[1;32m" << "Le compteur est à " << "\033[1;35m"<< compteur << "\033[0m"<< "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "C'est à vous de jouer" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Pour vous les actions possibles sont : " << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "1. Jouer une carte" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "2. Piocher une carte" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "3. Déclarer remporter une frontière" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "4. Abandonner" << "\033[0m" << std::endl;
            std::cout << "\033[1;35m" << "----------------------------------------------" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Veuillez sélectionner une action : " << "\033[0m" << std::endl;
            std::cin >> choice;
            while (choice < 1 || choice > 5) {
                std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une action valide." << "\033[0m"
                          << std::endl;
                std::cout << "\033[1;32m" << "Veuillez sélectionner une action : " << "\033[0m" << std::endl;
                std::cin >> choice;
            }

            switch (choice) {
                case 1:

                    // Action 1: Jouer une carte
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m" << std::endl;
                    int cardChoice;
                    std::cin >> cardChoice;
                    while (cardChoice < 1 || cardChoice > pPlayer->getHand().size()) {
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une carte valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une carte à jouer : " << "\033[0m"
                                  << std::endl;
                        std::cin >> cardChoice;
                    }
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoice;
                    std::cin >> borderChoice;
                    while (borderChoice < 1 || borderChoice > 9) {
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin >> borderChoice;
                    }
                    borderChoice--;
                    if (!handlepalycard(pPlayer, board, cardChoice, borderChoice)) {
                        std::cout << "\033[1;32m" << "Vous ne pouvez pas jouer cette carte sur cette frontière."
                                  << "\033[0m" << std::endl;
                        choice = 0;
                        goto action;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez joué la carte " << cardChoice << " sur la frontière "
                                  << borderChoice << "\033[0m" << std::endl;
                        count_action++;
                    }

                    break;

                case 2:
                    // Action 2: Piocher une carte
                    if (!handlepioche(pPlayer, board)) {
                        std::cout << "\033[1;32m" << "Vous ne pouvez pas piocher de carte." << "\033[0m" << std::endl;
                        choice = 0;
                        goto action;
                    } else { std::cout << "\033[1;32m" << "Vous avez pioché une carte." << "\033[0m" << std::endl;
                        count_action++;}

                    break;

                case 3:
                    // Action 3 : Déclarer remporter une frontière
                    std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                    int borderChoice2;
                    std::cin >> borderChoice2;
                    while (borderChoice2 < 1 || borderChoice2 > 9) {
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une frontière valide."
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[1;32m" << "Veuillez sélectionner une frontière : " << "\033[0m" << std::endl;
                        std::cin >> borderChoice2;
                    }
                    borderChoice2--;
                    if (!handledeclare(pPlayer, board)) {
                        std::cout << "\033[1;32m" << "Vous ne pouvez pas déclarer cette frontière." << "\033[0m"
                                  << std::endl;
                        choice = 0;
                        goto action;
                    } else {
                        std::cout << "\033[1;32m" << "Vous avez déclaré la frontière " << borderChoice2 << "\033[0m"
                                  << std::endl;
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
                        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une action valide."
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
                    std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une action valide." << "\033[0m"
                              << std::endl;
                    break;
            }
            if(count_action == 2){
                std::cout << "\033[1;32m" << "Vous avez effectué les actions necessaires. Vous voulez passer votre tour ? (y/n)" << "\033[0m" << std::endl;
                char passChoice;
                std::cin >> passChoice;
                while (passChoice != 'y' && passChoice != 'n') {
                    std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une action valide."
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
                    choice = 0;
                    goto action;
                }
            }
        }
        board->setCompteur(board->getCompteur()+1);
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
        show_action_possible_normal(pPlayer, board);


    }
    void show_board_tactical() {

    }





    void show_menu_principal() {
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
        std::cin >> choix;
        while (choix < 1 || choix > 3) {
            std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
            std::cin >> choix;
        }
        switch (choix) {
            case 1:
                std::cout << "\033[1;35m"<< "Vous avez choisi de commencer une nouvelle partie (version 1)" << std::endl;
                std::cout << "\033[1;35m"<< "----------------------------------------------" << std::endl;
                std::cout << "\033[1;35m"<< "1. " << "Commencer une nouvelle partie comme la mode normale" << "\033[0m" << std::endl;
                std::cout << "\033[1;35m"<< "2. " << "Commencer une nouvelle partie comme la mode tactique" << "\033[0m" << std::endl;
                std::cout << "\033[1;35m"<< "3. " << "Retour" << "\033[0m" << std::endl;
                std::cin >> choix;
                while (choix < 1 || choix > 3) {
                    std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
                    std::cin >> choix;
                }
                switch (choix) {
                    case 1:
                        std::cout << "\033[1;32m" << "Vous avez choisi de commencer une nouvelle partie comme la mode normale" << "\033[0m"<<"\n"<< std::endl;
                        goto  version1_normal;
                        break;
                    case 2:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de commencer une nouvelle partie comme la mode tactique"<< "\033[0m" <<"\n"<< std::endl;
                        show_board_tactical();
                        break;
                    case 3:
                        std::cout<< "\033[1;32m"  << "Vous avez choisi de retourner" << "\033[0m"<<"\n"<< std::endl;
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
                std::cin >> choix;
                while (choix < 1 || choix > 3) {
                    std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
                    std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
                    std::cin >> choix;
                }
                switch (choix) {
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
        version1_normal:
        Model::Controller controller(1, "Classique");
        Model::Player* human = controller.getPlayer(0);
        Model::Player* AI = controller.getPlayer(1);
        Model::Board *board = Model::SchottenTottenBoard::getInstance();
        board->createClanDeck();
        std::cout << "\033[1;32m"<< "Le jeu commence" << "\033[0m"<< std::endl;
        std::cout << "\033[1;35m"<< "----------------------------------------------" << "\033[0m"<< std::endl;
        std::cout << "\033[1;32m"<< "Vous avez 6 cartes dans votre main" << "\033[0m"<< std::endl;
        std::cout << "\033[1;35m"<< "----------------------------------------------" << "\033[0m"<< std::endl;
        std::cout << "\033[1;32m"<< "Vous voulez commencer à jouer en premier ou en deuxième?" << "\033[0m"<< std::endl;
        std::cout << "\033[1;35m"<< "----------------------------------------------" << "\033[0m"<< std::endl;
        std::cout << "\033[1;32m"<< "1. " << "Commencer en premier(La place de la carte que vous jouez est à gauche)" << "\033[0m" << std::endl;
        std::cout << "\033[1;32m"<< "2. " << "Commencer en deuxième(La place de la carte que vous jouez est à droite)" << "\033[0m" << std::endl;
        std::cin >> choix;
        while (choix < 1 || choix > 2) {
            std::cout << "\033[1;31m" << "Vous n'avez pas choisi une option valide" << "\033[0m" << std::endl;
            std::cout << "\033[1;32m" << "Votre choix : " << "\033[0m";
            std::cin >> choix;
        }
        switch (choix) {
            case 1:
                std::cout << "\033[1;32m" << "Vous avez choisi de commencer en premier" << "\033[0m"<<"\n"<< std::endl;
                human->setSide("left");
                human->addCard(board->getClanDeck()->draw());
                human->addCard(board->getClanDeck()->draw());
                human->addCard(board->getClanDeck()->draw());
                human->addCard(board->getClanDeck()->draw());
                human->addCard(board->getClanDeck()->draw());
                human->addCard(board->getClanDeck()->draw());
                board->getBorders()[0]->putCardLeft(board->getClanDeck()->draw());
                board->getBorders()[1]->putCardLeft(board->getClanDeck()->draw());
                board->getBorders()[1]->putCardRight(board->getClanDeck()->draw());
                board->getBorders()[1]->putCardLeft(board->getClanDeck()->draw());
                break;
            case 2:
                std::cout << "\033[1;32m" << "Vous avez choisi de commencer en deuxième" << "\033[0m"<<"\n"<< std::endl;
                AI->setSide("right");
                AI->addCard(board->getClanDeck()->draw());
                AI->addCard(board->getClanDeck()->draw());
                AI->addCard(board->getClanDeck()->draw());
                AI->addCard(board->getClanDeck()->draw());
                AI->addCard(board->getClanDeck()->draw());
                AI->addCard(board->getClanDeck()->draw());
                board->getBorders()[0]->putCardLeft(board->getClanDeck()->draw());
                board->getBorders()[1]->putCardLeft(board->getClanDeck()->draw());
                board->getBorders()[1]->putCardRight(board->getClanDeck()->draw());
                board->getBorders()[1]->putCardLeft(board->getClanDeck()->draw());
                show_board_normal(AI,board);
                break;

        }


        while(1)
        {   if(human->getSide()=="left")
            {show_board_normal(human,board);
            show_board_normal(AI,board);}
            else
            {show_board_normal(AI,board);
            show_board_normal(human,board);}
        }



    }



}