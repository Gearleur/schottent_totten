#include <iostream>
#include "Model/Board/Board.h"
#include "Model/Border/Border.h"
#include "Model/Player/Player.h"
#include "Model/Card/Card.h"
#include "Model/Game/Game.h"
#include "Controler/Controler.h"
#include "Vue/menu.h"
using namespace std;

int main() {
    // Création du contrôleur
    Model::Controller controller(2, "Classique");

    // Affichage des attributs des joueurs
    Model::Player* player1 = controller.getPlayer(0);
    Model::Player* player2 = controller.getPlayer(1);
    Model::Player* player3 = controller.getPlayer(2);
    Model::Player* player4 = controller.getPlayer(3);
    if (player1) {
        std::cout << "Attributs du joueur 1 :" << std::endl;
        std::cout << "Nom : " << player1->getName() << std::endl;
        std::cout << "Main : ";
        for (const auto& card : player1->getHand()) {
            std::cout << card->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Frontières : ";
        for (const auto& border : player1->getBorders()) {
            std::cout << border->getPosition() << " ";
        }
        std::cout << std::endl;
    }

    // Affichage des attributs du joueur 2
    if (player2) {
        std::cout << "Attributs du joueur 2 :" << std::endl;
        std::cout << "Nom : " << player2->getName() << std::endl;
        std::cout << "Main : ";
        for (const auto& card : player2->getHand()) {
            std::cout << card->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Frontières : ";
        for (const auto& border : player2->getBorders()) {
            std::cout << border->getPosition() << " ";
        }
        std::cout << std::endl;
    }

    if (player3) {
        std::cout << "Attributs du joueur 3 :" << std::endl;
        std::cout << "Nom : " << player3->getName() << std::endl;
        std::cout << "Main : ";
        for (const auto& card : player3->getHand()) {
            std::cout << card->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Frontières : ";
        for (const auto& border : player3->getBorders()) {
            std::cout << border->getPosition() << " ";
        }
        std::cout << std::endl;
    }

    if (player4) {
        std::cout << "Attributs du joueur 1 :" << std::endl;
        std::cout << "Nom : " << player4->getName() << std::endl;
        std::cout << "Main : ";
        for (const auto& card : player4->getHand()) {
            std::cout << card->getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Frontières : ";
        for (const auto& border : player4->getBorders()) {
            std::cout << border->getPosition() << " ";
        }
        std::cout << std::endl;
    }
    // Affichage des attributs des frontières
    for (int i = 0; i < 9; ++i) {
        Model::Border* border = controller.getBorder(i);
        if (border) {
            std::cout << "Attributs de la frontière " << i << " :" << std::endl;
            std::cout << "Position : " << border->getPosition() << std::endl;
            std::cout << "Propriétaire : " << (border->getOwner() ? border->getOwner()->getName() : "Aucun") << std::endl;
        }
    }

    // Affichage des attributs du jeu
    Model::Game* game = controller.getGame();
    if (game) {
        std::cout << "Attributs du jeu :" << std::endl;
        std::cout << "Version : " << game->getVersion() << std::endl;
        std::cout << "Variante : " << game->getVariante() << std::endl;
    }
    Vue::show_menu_principal();

    return 0;
}
