//
// Created by leeyu on 22/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_TACTIC_H
#define SCHOTTENT_TOTTEN_TACTIC_H
#include "../Card.h"
#include <iostream>

namespace Model
{
    class Tactic : public Card
    {
        protected:
        Special tactic_card_type;
        public:
        Tactic(Numbered number, Color color,Special type): Card(number, color, Type(1), "","",nullptr),tactic_card_type(type){
            std::cout<< "***** TACTIC CARD CONSTRUCTOR *****"<< std::endl;
        };
        virtual ~Tactic(){
            std::cout<< "***** TACTIC CARD DESTRUCTOR *****"<< std::endl;
        };
        virtual void showCard() const = 0;
    };
}



#endif //SCHOTTENT_TOTTEN_TACTIC_H
