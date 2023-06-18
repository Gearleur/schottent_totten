//
// Created by leeyu on 22/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_DISCARDDECK_H
#define SCHOTTENT_TOTTEN_DISCARDDECK_H


#include "../Deck.h"

namespace Model {
    class DiscardDeck : public Deck {
    private:
        static DiscardDeck* Instance_discardDeck;
        DiscardDeck();
    public:
        static DiscardDeck* getInstance_discardDeck(){
            if(Instance_discardDeck == nullptr)
                Instance_discardDeck = new DiscardDeck();
            return Instance_discardDeck;};
        void addCard(Card *card) override;
        void fillDeck() override;
    };
}

#endif //SCHOTTENT_TOTTEN_DISCARDDECK_H