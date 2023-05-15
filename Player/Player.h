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

using namespace std;

class Player {
    protected:
        int id;
        string name;
        vector<Card*> hand;

    public:
        static int idCounter;

        /* constructors */
        Player(const string& name, const vector<Card*>& hand): id(idCounter++), name(name), hand(hand){};

        /* getters */
        int getId() const { return id; };
        string getName() const { return name; };
        vector<Card*> getHand() const { return hand; };


        /* fonctions */
        void addCard(Card* card) { hand.push_back(card); };
        void removeCard(Card* card) { hand.erase(find(hand.begin(), hand.end(),card)); };
        void removeCard(int index) { hand.erase(hand.begin() + index); };

        /* virtual functions */
        virtual bool isAI() const = 0;
        virtual ~Player() = default;



};


#endif //SCHOTTENT_TOTTEN_PLAYER_H
