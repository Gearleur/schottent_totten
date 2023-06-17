//
// Created by leeyu on 22/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_DISCARDDECK_H
#define SCHOTTENT_TOTTEN_DISCARDDECK_H


#include "../Deck.h"

namespace Model {
    class SchottenTottenBoard;
    class DiscardDeck : public Deck {
    private:
        friend class SchottenTottenBoard;
        static DiscardDeck* Instance_discardDeck;
        DiscardDeck();
        void operator=(const DiscardDeck&);
    public:
        static DiscardDeck* getInstance_discardDeck(){
            if(Instance_discardDeck == nullptr)
                Instance_discardDeck = new DiscardDeck();
            return Instance_discardDeck;};
        void addCard(Card *card) override;
        void fillDeck() override;
        static void freeInstance();
        ~DiscardDeck() override{
            for(auto card : Instance_discardDeck->getDeck())
                delete card;
            std::cout <<"***** DiscardDeck DESTRUCTOR *****" <<std::endl;
        }
    };
}

#endif //SCHOTTENT_TOTTEN_DISCARDDECK_H
