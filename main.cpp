#include <iostream>
#include "Model/Border/Border.h"
#include "Model/Player/Player.h"
#include "Model/Card/Card.h"
#include "Model/Card/Clan/Clan.h"
#include "Model/Game/Game.h"
#include "Controler/Controler.h"
using namespace std;

int main() {

    // Création du contrôleur
    Model::Controller controller(1, "Classique");
    // Affichage des attributs des joueurs
    Model::Player* player1 = controller.getPlayer(0);
    if (player1) {
        std::cout << "Attributs du joueur 1 :" << std::endl;
        std::cout << "Nom : " << player1->getName() << std::endl;
        std::cout << "Main : ";
        for (const auto& card : player1->getHand()) {
            card->showCard();
        }
        std::cout << std::endl;
        std::cout << "Frontières : ";
        for (const auto& border : player1->getBorders()) {
            std::cout << border->getPosition() << " ";
        }
        std::cout << std::endl;
    }
    return 0;


}
