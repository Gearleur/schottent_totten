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
#include "../Utils/enums.h"
#include "../Player/Player.h"

class Player;

class Border {
private:
    std::vector<Card*> leftBorder;
    std::vector<Card*> rightBorder;
    int maxCards;
    int currentCardsLeft;
    int currentCardsRight;
    Player* owner;

    void addCard(Card* card, vector<Card*> border);
    bool isFull(vector<Card*> border);
    bool isEmpty(vector<Card*> border);
    bool isWinning(vector<Card*> border);

    /* Getter */
    Player* getOwner();
    vector<Card*> getLeftBorder();
    vector<Card*> getRightBorder();
    int getMaxCards();
    int getCurrentCardsLeft();
    int getCurrentCardsRight();

    /* Setter */
    void setOwner(Player* player);
    void setLeftBorder(vector<Card*> border);
    void setRightBorder(vector<Card*> border);
    void setMaxCards(int maxCards);
    void setCurrentCardsLeft(int currentCardsLeft);
    void setCurrentCardsRight(int currentCardsRight);

    friend class Game;

public:
    Border();
    ~Border();
};



#endif //SCHOTTENT_TOTTEN_BORDER_H
