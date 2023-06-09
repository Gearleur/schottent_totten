//
// Created by leeyu on 22/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_TACTICDECK_H
#define SCHOTTENT_TOTTEN_TACTICDECK_H

#include "../Deck.h"


namespace Model {
    class TacticDeck : public Deck {
    private:
        static TacticDeck* Instance_tacticDeck;
        TacticDeck();
    public:
        static TacticDeck* getInstance_tacticDeck(){
            if(Instance_tacticDeck == nullptr)
                Instance_tacticDeck = new TacticDeck();
            return Instance_tacticDeck ;};
        void addCard(Card *card) override;
        void fillDeck() override;
    };
}


#endif //SCHOTTENT_TOTTEN_TACTICDECK_H
