//
// Created by alexa on 15/05/2023.
//

#include <stdexcept>
#include <iostream>
#include "Border.h"
#include "../Player/Player.h"

namespace Model{

    Border::Border(int position, Player* owner) {
        this->position = position;
        this->maxCards = 3;
        this->currentCardsLeft = 0;
        this->currentCardsRight = 0;
        this->owner = owner;
    }

    void Border::addCardLeft(Card *card) {
        if (!this->isLeftFull()) {
            leftBorder.push_back(card);
            currentCardsLeft++;
        } else {
            throw std::invalid_argument("Border is full");
        }

    }
    void Border::addCardRight(Card *card) {
        if (!this->isRightFull()) {
            rightBorder.push_back(card);
            currentCardsRight++;
        } else {
            throw std::invalid_argument("Border is full");
        }
    }
    void Border::removeCardLeft(Card* card) {
        auto it = std::find(rightBorder.begin(), rightBorder.end(), card);

        if (it != leftBorder.end()) {
            leftBorder.erase(it);
            currentCardsLeft--;
        }
    }

    void Border::removeCardRight(Card* card) {
        auto it = std::find(rightBorder.begin(), rightBorder.end(), card);

        if (it != rightBorder.end()) {
            rightBorder.erase(it);
            currentCardsRight--;
        }
    }

    void Border::putCardLeft(Card *card) {
        if (!this->isLeftFull()) {
            leftBorder.insert(leftBorder.end(), card);
            currentCardsLeft++;
        } else {
            throw std::invalid_argument("Border is full");
        }
    }

    void Border::putCardRight(Card *card) {
        if (!this->isRightFull()) {
            rightBorder.insert(rightBorder.end(), card);
            currentCardsRight++;
        } else {
            throw std::invalid_argument("Border is full");
        }

    }

    void Border::showBorder() const {
        std::cout << "\033[1;32mPosition : " << "\033[1;35m"<< position + 1 << "\033[0m"<< "\033[0m" << std::endl;
        std::cout << "\033[1;32mPropriétaire : " << "\033[1;35m"<< (owner ? owner->getName() : "Aucun") << "\033[0m"<< "\033[0m" << std::endl;
        int index = 1;
        std::cout << "\033[1;32mBordure gauche : \033[0m";
        for (const auto& card : leftBorder) {
            std::cout << "\033[1;35m[ Carte " << index++ << " : \033[0m";
            card->showCard();
            std::cout << "\033[1;35m] \033[0m";
        }
        std::cout << std::endl;
        index = 1;
        std::cout << "\033[1;32mBordure droite : \033[0m";
        for (const auto& card : rightBorder) {
            std::cout << "\033[1;35m[ Carte " << index++ << " : \033[0m";
            card->showCard();
            std::cout << "\033[1;35m] \033[0m";
        }
        std::cout << std::endl;
        std::cout << "\033[1;32mCartes actuelles - Gauche : " << "\033[1;35m"<< currentCardsLeft<< "\033[0m" << "\033[1;32m"<< " / Droite : "<< "\033[0m"<< "\033[1;35m" << currentCardsRight << "\033[0m"<< "\033[0m" << std::endl;
    }

    void Border::showBorderTactically() const {
        std::cout << "\033[1;32mPosition : " << "\033[1;35m"<< position + 1 << "\033[0m"<< "\033[0m" << std::endl;
        std::cout << "\033[1;32mPropriétaire : " << "\033[1;35m"<< (owner ? owner->getName() : "Aucun") << "\033[0m"<< "\033[0m" << std::endl;
        int index = 1;
        std::cout << "\033[1;32mBordure gauche : \033[0m";
        for (const auto& card : leftBorder) {
            std::cout << "\033[1;35m[ Carte " << index++ << " : \033[0m";
            card->showCard();
            std::cout << "\033[1;35m] \033[0m";
        }
        std::cout << std::endl;
        index = 1;
        std::cout << "\033[1;32mBordure droite : \033[0m";
        for (const auto& card : rightBorder) {
            std::cout << "\033[1;35m[ Carte " << index++ << " : \033[0m";
            card->showCard();
            std::cout << "\033[1;35m] \033[0m";
        }
        std::cout << std::endl;
        index = 1;
        std::cout << "\033[1;32mTuile Borne : \033[0m";
        for (const auto& card : borne) {
            std::cout << "\033[1;35m[ Carte " << index++ << " : \033[0m";
            card->showCard();
            std::cout << "\033[1;35m] \033[0m";
        }
        std::cout << std::endl;
        std::cout << "\033[1;32mCartes actuelles - Gauche : " << "\033[1;35m"<< currentCardsLeft<< "\033[0m" << "\033[1;32m"<< " / Droite : "<< "\033[0m"<< "\033[1;35m" << currentCardsRight << "\033[0m"<< "\033[0m" << "\033[1;32m / Borne : " << "\033[1;35m"<< borne.size()<< "\033[0m"<< std::endl;
    }

    void Border::removeCardLeft(int index) {
        if (index < 0 || index >= leftBorder.size()) {
            throw std::invalid_argument("Index out of range");
        }
        leftBorder.erase(leftBorder.begin() + index);
        currentCardsLeft--;

    }
    void  Border::removeCardRight(int index) {
        if (index < 0 || index >= rightBorder.size()) {
            throw std::invalid_argument("Index out of range");
        }
        rightBorder.erase(rightBorder.begin() + index);
        currentCardsRight--;
    }


    Border::~Border() = default;


}