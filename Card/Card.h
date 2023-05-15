//
// Created by alexa on 15/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_CARD_H
#define SCHOTTENT_TOTTEN_CARD_H

#include "../Utils/enums.h"
#include "../Player/Player.h"

class Player;

//la class card est la classe abstraite qui contient les fonctions principales pour generer une carte
//cette classe abstraite engendre deux classe filles qui sont les deux types de cartes
//Il y a les cartes numérotées et les cartes spéciales
//les cartes numérotées sont les cartes de 1 à 9 et 6 couleurs différentes
//les cartes spéciales sont des cartes avec des pouvoirs spéciaux
class Card {
    protected:
        Numbered number;
        Color color;
        Type type;
        char* name;
        char* description;
        Player* owner = nullptr;

    public:
        Card(Numbered number, Color color, Type type, char* name= nullptr, char* description= nullptr, Player* owner= nullptr):
            number(number), color(color), type(type), name(name), description(description), owner(owner){};

        Card() {};
        virtual ~Card()=default; //destructor en virtual car Card Abstract

        //getters
        Numbered getNumber() const { return number; };
        Color getColor() const { return color; };
        Type getType() const { return type; };
        char* getName() const { return name; };
        char* getDescription() const { return description; };
        Player* getOwner() const { return owner; };

        //setters
        void setNumber(Numbered number) { this->number = number; };
        void setColor(Color color) { this->color = color; };
        void setType(Type type) { this->type = type; };
        void setOwner(Player* owner) { this->owner = owner; };

        //fonction

};


#endif //SCHOTTENT_TOTTEN_CARD_H
