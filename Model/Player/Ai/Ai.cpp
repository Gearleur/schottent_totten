//
// Created by alexa on 18/06/2023.
//

#include "Ai.h"

//create a classe AI that inherits from Player
namespace Model{
    class Ai : public Player{
    private:
        friend class PlayerControllerFactory;
    public:
        //constructeur Ai avec un nom et une main et un vector borders vide par défaut qui se base de la construction de Player
        Ai(const std::string &name, const std::vector<Card *> &hand, const std::vector<Border *> &borders = std::vector<Border *>()) : Player(name, hand, borders) {};

        bool isAI() const override { return true; };

    };
}

