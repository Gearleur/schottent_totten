//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_BORDER_H
#define SCHOTTENT_TOTTEN_BORDER_H

//cette classe représente les 7 emplacements de territoire a capturer
//elle contient deux tableax de cartes
//un nombres max de cartes par tableau
//un nombre de cartes actuel par tableau
//un possesseur de territoire
//une fonction pour ajouter une carte dans un tableau
//une fonction pour vérifier si un tableau est plein
//une fonction pour vérifier si un tableau est vide
//une fonction pour vérifier si un tableau est gagnant
//seul la classe Game peut créer un objet de cette classe
//la classe Game peut accéder aux attributs de cette classe
//la classe Game peut utiliser les fonctions de cette classe

#include <vector>
#include "../Card/Card.h"
#include "../../Utils/enums.h"
#include "../Player/Player.h"

class Player;

class Border {
private:
    int position;
    std::vector<Card*> leftBorder;
    std::vector<Card*> rightBorder;
    int maxCards;
    int currentCardsLeft;
    int currentCardsRight;
    Player* owner;

    void addCard(Card* card, std::vector<Card*> border);
    bool isFull(std::vector<Card*> border);
    bool isEmpty(std::vector<Card*> border);
    bool isWinning(std::vector<Card*> border);

    /* Getter */
    int getPosition(){ return position;}
    Player* getOwner(){ return owner;}
    std::vector<Card*> getLeftBorder(){ return leftBorder;}
    std::vector<Card*> getRightBorder(){ return rightBorder;}
    int getMaxCards(){ return maxCards;}
    int getCurrentCardsLeft(){ return currentCardsLeft;}
    int getCurrentCardsRight(){ return currentCardsRight;}

    /* Setter */
    void setOwner(Player* player){ owner = player;}
    void setLeftBorder(std::vector<Card*> border){ leftBorder = border;}
    void setRightBorder(std::vector<Card*> border) { rightBorder = border;}
    void setMaxCards(int maxCards) { this->maxCards = maxCards;}
    void setCurrentCardsLeft(int currentCardsLeft) { this->currentCardsLeft = currentCardsLeft;}
    void setCurrentCardsRight(int currentCardsRight) { this->currentCardsRight = currentCardsRight;}

    void addCardLeft(Card* card){ addCard(card, leftBorder);}
    void addCardRight(Card* card){ addCard(card, rightBorder);}

    friend class Game;

public:
    Border(int position, Player* owner = nullptr);
    ~Border();
};



#endif //SCHOTTENT_TOTTEN_BORDER_H
