//
// Created by leeyu on 22/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_TACTIC_H
#define SCHOTTENT_TOTTEN_TACTIC_H
#include "../Card.h"


namespace Model
{
    class Tactic : public Card
    {
    protected:
        Special tactic_card_type;
    public:
        Tactic(Numbered number, Color color,Special type): Card(number, color, Type(1), "","",nullptr),tactic_card_type(type){};
        virtual ~Tactic()=default;
        virtual void showCard() const = 0;
        virtual std::string getCardInfo() const = 0;
    };
}



#endif //SCHOTTENT_TOTTEN_TACTIC_H