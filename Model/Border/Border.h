//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_BORDER_H
#define SCHOTTENT_TOTTEN_BORDER_H

// cette classe représente les 7 emplacements de territoire a capturer
// elle contient deux tableax de cartes
// un nombres max de cartes par tableau
// un nombre de cartes actuel par tableau
// un possesseur de territoire
// une fonction pour ajouter une carte dans un tableau
// une fonction pour vérifier si un tableau est plein
// une fonction pour vérifier si un tableau est vide
// une fonction pour vérifier si un tableau est gagnant
// seul la classe Game peut créer un objet de cette classe
// la classe Game peut accéder aux attributs de cette classe
// la classe Game peut utiliser les fonctions de cette classe

#include <vector>
#include "../Card/Card.h"

namespace Model
{
    class Card;
    class Player;
    class Controller;
    class Border
    {
    private:
        friend class Game;
        friend class Controller;
        friend class Board;
    protected:
        int position;
        std::vector<Card *> leftBorder = std::vector<Card *>();
        std::vector<Card *> rightBorder = std::vector<Card *>();
        int maxCards = 3;
        int currentCardsLeft;
        int currentCardsRight;
        Player *owner;

        bool isEmpty() const { return currentCardsLeft == 0 && currentCardsRight == 0; }

        /* Setter */

        void setLeftBorder(std::vector<Card *> border) { leftBorder = border; }
        void setRightBorder(std::vector<Card *> border) { rightBorder = border; }
        void setCurrentCardsLeft(int CurrentCardsLeft) { this->currentCardsLeft = CurrentCardsLeft; }
        void setCurrentCardsRight(int CurrentCardsRight) { this->currentCardsRight = CurrentCardsRight; }

        void addCardLeft(Card *card);
        void addCardRight(Card *card);

    public:
        void setOwner(Player *player) { owner = player; }
        void setMaxCards(int Maxcards) { this->maxCards = Maxcards; }
        bool isLeftFull() const { return currentCardsLeft == maxCards; }
        bool isRightFull() const { return currentCardsRight == maxCards; }
        /* Getter */
        int getPosition() const { return position; }
        Player *getOwner() const { return owner; }
        const std::vector<Card *> &getLeftBorder() const { return leftBorder; }
        const std::vector<Card *> &getRightBorder() const { return rightBorder; }
        void putCardLeft(Card *card);
        void putCardRight(Card *card);
        int getMaxCards() const { return maxCards; }
        int getCurrentCardsLeft() const { return currentCardsLeft; }
        int getCurrentCardsRight() const { return currentCardsRight; }
        explicit Border(int position, Player *owner = nullptr);
        virtual ~Border();
        void showBorder() const;
    };
}

#endif // SCHOTTENT_TOTTEN_BORDER_H