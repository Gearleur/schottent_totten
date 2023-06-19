//
// Created by leeyu on 19/06/2023.
//


#include <limits>
#include "handle.h"

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
        pBoard->getBorders()[bordernumber]->removeCardRight(cardnumber);
    }
    else
    {pBoard->getBorders()[--bordernumber2]->putCardRight(pBoard->getBorders()[bordernumber]->getLeftBorder()[--cardnumber]);
        pBoard->getBorders()[bordernumber]->removeCardLeft(cardnumber);
    }
}
void handleStratege(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller)
{
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
        pBoard->getBorders()[bordernumber]->removeCardRight(cardnumber);
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

bool handlepiocheTactic(Model::Player * pPlayer, Model::Board *pBoard, size_t max_card = 9){
    if(!pBoard->getTacticDeck()->getDeck().empty() && pPlayer->getHand().size() < max_card){
        pPlayer->addCard(pBoard->getTacticDeck()->draw());
        return true;
    }
    else
        return false;
}
void handleChasseurdeTete(Model::Player * pPlayer, Model::Board *pBoard, size_t max)
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
            handlepiocheTactic(pPlayer, pBoard, max);
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
    }while(number <2);
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
        handleBansheePlayer(pPlayer, pBoard->getBorders()[borderPosition]->getRightBorder(), pBoard, controller);

    }
    else if(pPlayer->getSide()=="droite" && pBoard->getBorders()[--borderPosition]->getOwner() == nullptr){
        handleBansheePlayer(pPlayer, pBoard->getBorders()[borderPosition]->getLeftBorder(), pBoard, controller);
    }
}
void handleEspion(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller)
{
    int numberChoice, colorChoice = 0;
    std::cout << "Quelle couleur voulez-vous affecter à l'Espion ?" << std::endl;
    std::cin >> numberChoice;
    while (colorChoice < 1 || colorChoice > 6) {
        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une couleur valide."
                  << "\033[0m" << std::endl;
        std::cout << "\033[1;32m" << "Veuillez sélectionner une couleur à affecter : " << "\033[0m"
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> colorChoice;
    }
    card->setColor(static_cast<Color>(--colorChoice));
}
void handlePorteBouclier(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller)
{
    int numberChoice, colorChoice = 0;
    std::cout << "Quelle valeur voulez-vous affecter au PorteBouclier ?" << std::endl;
    std::cin >> numberChoice;
    while (numberChoice < 1 || numberChoice > 3) {
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
    while (colorChoice < 1 || colorChoice > 6) {
        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une couleur valide."
                  << "\033[0m" << std::endl;
        std::cout << "\033[1;32m" << "Veuillez sélectionner une couleur à affecter : " << "\033[0m"
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> colorChoice;
    }
    card->setNumber(static_cast<Numbered>(numberChoice));
    card->setColor(static_cast<Color>(--colorChoice));
}
bool handleplaytacticalcard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice, Model::Controller *controller) {
    if(borderChoice!=0)
    {if(pBoard->getBorders()[borderChoice]->getOwner()!= nullptr) {
            return false;
        }}
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
            handleChasseurdeTete(pPlayer, pBoard,9);
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
bool handledeclare(Model::Player *pPlayer, Model::Board *pBoard, int borderChoice, Model::Controller *controller) {
    if(pBoard->getBorders()[borderChoice]->getColinMaillard()==1){
        return handleCollinMaillard(pPlayer,controller->getPlayer()[!pPlayer->getId()],pBoard,borderChoice,controller);
    }
    if(pPlayer->getSide()=="gauche") {
        setValuesTacticCards(pPlayer, pBoard, &pBoard->getBorders()[borderChoice]->getLeftBorder(), borderChoice,controller);
    } else {
        setValuesTacticCards(pPlayer, pBoard, &pBoard->getBorders()[borderChoice]->getRightBorder(), borderChoice,controller);
    }
    return controller->canClaimBorder(pPlayer->getId(), pBoard, borderChoice);
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
void handleJoker(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller)
{
    int numberChoice, colorChoice = 0;
    std::cout << "Quelle valeur voulez-vous affecter au Joker ?" << std::endl;
    std::cin >> numberChoice;
    while (numberChoice < 1 || numberChoice > 9) {
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
    while (colorChoice < 1 || colorChoice > 6) {
        std::cout << "\033[1;32m" << "Choix invalide. Veuillez sélectionner une couleur valide."
                  << "\033[0m" << std::endl;
        std::cout << "\033[1;32m" << "Veuillez sélectionner une couleur à affecter : " << "\033[0m"
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> colorChoice;
    }
    card->setNumber(static_cast<Numbered>(numberChoice));
    card->setColor(static_cast<Color>(--colorChoice));
}