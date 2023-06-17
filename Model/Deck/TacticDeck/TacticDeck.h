//
// Created by leeyu on 22/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_TACTICDECK_H
#define SCHOTTENT_TOTTEN_TACTICDECK_H

#include "../Deck.h"


namespace Model {
    class SchottenTottenBoard;
    class TacticDeck : public Deck {
    private:
        friend class SchottenTottenBoard;
        static TacticDeck* Instance_tacticDeck;
        TacticDeck();
        void operator=(const TacticDeck&);
        ~TacticDeck() override{
            for(auto card : Instance_tacticDeck->getDeck())
                delete card;
            std::cout <<"***** TacticDeck DESTRUCTOR *****" <<std::endl;
        }
    public:
        static TacticDeck* getInstance_tacticDeck(){
            if(Instance_tacticDeck == nullptr)
                Instance_tacticDeck = new TacticDeck();
            return Instance_tacticDeck ;};
        void addCard(Card *card) override;
        void fillDeck() override;
        static void freeInstance();
    };
}


#endif //SCHOTTENT_TOTTEN_TACTICDECK_H
