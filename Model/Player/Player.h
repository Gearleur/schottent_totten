//
// Created by alexa on 15/05/2023.
//

#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "../Border/Border.h"
#include "../EventManager/EventManager.h"
#include "../Card/Card.h"


namespace Model {
    class Card;
    class Border;
    class Player /*: public Observer*/{
    protected:
        friend class Controller;
        int id;
        std::string name;
        std::string side;
        std::vector<Card *> hand;
        std::vector<Border *> borders;


    public:
        static int idCounter;

        /* constructors */
        /*les borders ne sont pas demander et initialisées à 0*/
        /*Updated upstream*/
        Player(const std::string& name, const std::vector<Card*>& hand, const std::vector<Border*>& borders)
                : id(idCounter++), name(name), hand(hand), borders(borders) {
        }

        /*Stashed changes*/
        /* getters */
        const int &getId() const { return id; };

        const std::string &getName() const { return name; };

        const std::vector<Card *> &getHand() const { return hand; };

        const std::vector<Border *> &getBorders() const { return borders; };


        /* fonctions */
        void addCard(Card *card) { hand.push_back(card); };

        void removeCard(Card *card) { hand.erase(find(hand.begin(), hand.end(), card)); };

        void removeCard(int index) { hand.erase(hand.begin() + index); };

        void addBorder(Border *border) { borders.push_back(border); };

        void removeBorder(Border *border) { borders.erase(find(borders.begin(), borders.end(), border)); };

        void removeBorder(int index) { borders.erase(borders.begin() + index); };

        void showHand() const;
        void setSide(const std::string& side) { this->side = side; }
        const std::string& getSide() const { return side; }
        void setName(const std::string &n) {this->name = n;}
        void Notify(const std::string& message){
            std::cout << "Notification received: " << message << std::endl;
        }
        //void update(const std::string &event) override;
        /* virtual functions */
        virtual bool isAI() const = 0;//rend la classe abstraite et les classes filles doivent implémenter cette fonction
        virtual ~Player() = default;


    };
}