//
// Created by alexa on 18/06/2023.
//

#ifndef SCHOTTENT_TOTTEN_AI_H
#define SCHOTTENT_TOTTEN_AI_H

#include "../Player.h"
#include "../Human/Human.h"

//creer une ia a partir de player
namespace Model{
    namespace AI{
        class Ai : public Player{
        private:
            friend class PlayerControllerFactory;
        public:
            //constructeur Ai avec un nom et une main et un vector borders vide par défaut qui se base de la construction de Player
            Ai(const std::string &name, const std::vector<Card *> &hand, const std::vector<Border *> &borders = std::vector<Border *>()) : Player(name, hand, borders) {};

            bool isAI() const override { return true; };
        };
    }
}

#endif //SCHOTTENT_TOTTEN_AI_H
