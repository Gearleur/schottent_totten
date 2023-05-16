//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_PLAYER_H
#define SCHOTTENT_TOTTEN_PLAYER_H

#include <string>
#include <vector>
#include <algorithm>
#include "../Utils/enums.h"
#include "../Card/Card.h"

class Card;
class Border;

using namespace std;

class Player {
    protected:
        int id;
        string name;
        vector<Card*> hand;
        vector<Border*> borders;

    public:
        static int idCounter;

        /* constructors */
        Player(const string& name, const vector<Card*>& hand, const vector<Border*>& borders): id(idCounter++), name(name), hand(hand), borders(borders){};

        /* getters */
        const int& getId() const { return id; };
        const string& getName() const { return name; };
        const vector<Card*>& getHand() const { return hand; };
        const vector<Border*>& getBorders() const { return borders; };


        /* fonctions */
        void addCard(Card* card) { hand.push_back(card); };
        void removeCard(Card* card) { hand.erase(find(hand.begin(), hand.end(),card)); };
        void removeCard(int index) { hand.erase(hand.begin() + index); };

        void addBorder(Border* border) { borders.push_back(border); };
        void removeBorder(Border* border) { borders.erase(find(borders.begin(), borders.end(),border)); };
        void removeBorder(int index) { borders.erase(borders.begin() + index); };

        void showHand() const;

        /* virtual functions */
        virtual bool isAI() const = 0;
        virtual ~Player() = default;



};


#endif //SCHOTTENT_TOTTEN_PLAYER_H
