//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_PLAYER_H
#define SCHOTTENT_TOTTEN_PLAYER_H

#include <string>
#include <vector>
#include <algorithm>
#include "../../Utils/enums.h"
#include "../Card/Card.h"

class Card;
class Border;

class Player {
    protected:
        int id;
        std::string name;
        std::vector<Card*> hand;
        std::vector<Border*> borders;

    public:
        static int idCounter;

        /* constructors */
        Player(const std::string& name, const std::vector<Card*>& hand, const std::vector<Border*>& borders): id(idCounter++), name(name), hand(hand), borders(borders){};

        /* getters */
        const int& getId() const { return id; };
        const std::string& getName() const { return name; };
        const std::vector<Card*>& getHand() const { return hand; };
        const std::vector<Border*>& getBorders() const { return borders; };


        /* fonctions */
        void addCard(Card* card) { hand.push_back(card); };
        void removeCard(Card* card) { hand.erase(find(hand.begin(), hand.end(),card)); };
        void removeCard(int index) { hand.erase(hand.begin() + index); };

        void addBorder(Border* border) { borders.push_back(border); };
        void removeBorder(Border* border) { borders.erase(find(borders.begin(), borders.end(),border)); };
        void removeBorder(int index) { borders.erase(borders.begin() + index); };

        void showHand() const;

        /* virtual functions */
        virtual bool isAI() const = 0;//rend la classe abstraite et les classes filles doivent implémenter cette fonction
        virtual ~Player() = default;



};


#endif //SCHOTTENT_TOTTEN_PLAYER_H