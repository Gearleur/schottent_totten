#pragma once

#include "Board.h"
#include <iostream>
namespace Model
{
    class SchottenTottenBoard : public Board
    {
    private:
        static SchottenTottenBoard *instance;
        SchottenTottenBoard(){
            std::cout <<"***** SCHOTTEN TOTTEN BOARD CONSTRUCTOR *****" <<std::endl;
            ClanDeck::getInstance_clanDeck();
        }
        ~SchottenTottenBoard() {
            std::cout <<"***** SCHOTTEN TOTTEN BOARD DESTRUCTOR *****" <<std::endl;
            ClanDeck::freeInstance();
        }
        void operator=(const SchottenTottenBoard&);

    public:
        static void freeInstance(){
            delete instance;
            instance = nullptr;
        }
        static SchottenTottenBoard *getInstance()
        {
            if (instance == nullptr)
                instance = new SchottenTottenBoard();
            return instance;
        }
        static DiscardDeck *getDiscardDeck() {
            return DiscardDeck::getInstance_discardDeck(); }
        static ClanDeck *getClanDeck() {
            return ClanDeck::getInstance_clanDeck(); }
        static TacticDeck *getTacticDeck() {
            return TacticDeck::getInstance_tacticDeck(); }
        void update(const std::string & event) override;
    };

    class SchottenTottenBoardTactique : public Board
    {
    private:
        static SchottenTottenBoardTactique *instance;
        SchottenTottenBoardTactique(){
            std::cout <<"***** SCHOTTEN TOTTEN BOARD TACTIC CONSTRUCTOR *****" <<std::endl;
            ClanDeck::getInstance_clanDeck();
            TacticDeck::getInstance_tacticDeck();
            DiscardDeck::getInstance_discardDeck();
        }
        ~SchottenTottenBoardTactique() {
            std::cout <<"***** SCHOTTEN TOTTEN BOARD TACTIC DESTRUCTOR *****" <<std::endl;
            ClanDeck::freeInstance();
            DiscardDeck::freeInstance();
            TacticDeck::freeInstance();
        }
        void operator=(const SchottenTottenBoardTactique&);
    public:
        static void freeInstance(){
            delete instance;
            instance = nullptr;
        }
        static SchottenTottenBoardTactique *getInstance()
        {
            if (instance == nullptr)
                instance = new SchottenTottenBoardTactique;
            return instance;
        }
        static DiscardDeck *getDiscardDeck() {
            return DiscardDeck::getInstance_discardDeck(); }
        static ClanDeck *getClanDeck() {
            return ClanDeck::getInstance_clanDeck(); }
        static TacticDeck *getTacticDeck() {
            return TacticDeck::getInstance_tacticDeck(); }
        void update(const std::string & event) override;
    };
}