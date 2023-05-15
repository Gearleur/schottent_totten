//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_PLAYER_H
#define SCHOTTENT_TOTTEN_PLAYER_H

#include <string>
#include <vector>
#include "../Utils/enums.h"
#include "../Card/Card.h"

using namespace std;

class Player {
    protected:
        int id;
        string name;
        vector<Card> hand;

    public:
        static int idCounter;
        Player(const string& name, const vector<Card>& hand): name(name), hand(hand) { id = idCounter++; };

        /* Getters */
        int getId() const { return id; };
        string getName() const { return name; };
        vector<Card> getHand() const { return hand; };

        /* Setters */
        void setName(const string& name) { this->name = name; };
        void setHand(const vector<Card>& hand) { this->hand = hand; };

        /* Functions */
        void addCard(const Card& card);
        void removeCard(const Card& card);
        void removeCard(const int& index);
        void printHand() const;

        /* virtual functions */
        virtual bool isAI() const = 0;
        virtual ~Player() = default;



};


#endif //SCHOTTENT_TOTTEN_PLAYER_H
