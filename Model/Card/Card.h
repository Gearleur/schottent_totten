//
// Created by alexa on 15/05/2023.
//

#pragma once

#include <string>

#include "../../Utils/enums.h"
#include "../Player/Player.h"
//la class card est la classe abstraite qui contient les fonctions principales pour generer une carte
//cette classe abstraite engendre deux classe filles qui sont les deux types de cartes
//Il y a les cartes numérotées et les cartes spéciales
//les cartes numérotées sont les cartes de 1 à 9 et 6 couleurs différentes
//les cartes spéciales sont des cartes avec des pouvoirs spéciaux
namespace Model{
    class Player;
    class Card {
    protected:
        Numbered number;
        Color color;
        Type type;
        std::string name;
        std::string description;
        Player* owner = nullptr;

    public:
        Card(Numbered number, Color color, Type type, std::string name= "", std::string description= "", Player* owner= nullptr):
                number(number), color(color), type(type), name(name), description(description), owner(owner){};

        Card() {};
        virtual ~Card()=default; //destructor en virtual car Card Abstract

        //getters
        Numbered getNumber() const { return number; };
        Color getColor() const { return color; };
        Type getType() const { return type; };
        std::string getDescription() const { return description; };
        Player* getOwner() const { return owner; };
        int getTypeInt() const { return type; };



        //setters
        virtual void setNumber(Numbered number) { this->number = number; };
        virtual void setColor(Color color) { this->color = color; };
        void setType(Type type) { this->type = type; };
        void setOwner(Player* owner) { this->owner = owner; };

        //fonctions
        virtual void showCard() const = 0;
        virtual std::string getCardInfo() const = 0;
        virtual  std::string getNom() const = 0;

        //fonction

    };
}