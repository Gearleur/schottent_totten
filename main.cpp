#include "Vue/Vue.h"
using namespace std;

int main() {


    Vue::show_menu_principal();
    /*Model::Controller controller(1, "Classique");
    Model::Board *board = controller.getBoard();
    controller.addPlayer(new Model::Human("J1", std::vector<Model::Card *>()));
    controller.addPlayer(new Model::Human("J2", std::vector<Model::Card *>()));
    controller.getPlayer(0)->addCard(new Model::Clan(ONE, BLUE));
    controller.getPlayer(0)->addCard(new Model::Clan(TWO, BLUE));
    controller.getPlayer(0)->addCard(new Model::Clan(THREE, BLUE));
    controller.getPlayer(1)->addCard(new Model::Clan(FIVE, ORANGE));
    controller.getPlayer(1)->addCard(new Model::Clan(SIX, ORANGE));
    controller.getPlayer(1)->addCard(new Model::Clan(SEVEN, ORANGE));
    controller.getPlayer(0)->showHand();
    controller.getPlayer(1)->showHand();
    board->getBorders()[0]->putCardLeft(controller.getPlayer(0)->getHand()[0]);
    board->getBorders()[0]->putCardLeft(controller.getPlayer(0)->getHand()[1]);
    board->getBorders()[0]->putCardLeft(controller.getPlayer(0)->getHand()[2]);
    board->getBorders()[0]->putCardRight(controller.getPlayer(1)->getHand()[0]);
    board->getBorders()[0]->putCardRight(controller.getPlayer(1)->getHand()[1]);
    board->getBorders()[0]->putCardRight(controller.getPlayer(1)->getHand()[2]);
    std::cout <<controller.canClaimBorder(controller.getPlayer(0)->getId(), board, 0);
    */

    return 0;
}