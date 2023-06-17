//
// Created by alexa on 10/05/2023.
//

#include "Game.h"

namespace Model
{
    Game::~Game()
    {
        std::cout << "****** Game Destructor ******" << std::endl;
    }
    GameV1::GameV1(int v, const std::string& var) : Game(v, var)
    {
        SchottenTottenBoard::getInstance();
        decks.push_back(SchottenTottenBoard::getClanDeck());
    }
    SchottenTottenBoard *GameV1::getBoard() const { return SchottenTottenBoard::getInstance(); }
    GameV1::~GameV1(){
        SchottenTottenBoard::freeInstance();
    }
    GameV1Tactique::GameV1Tactique(int v, const std::string& var) : Game(v, var)
    {
        SchottenTottenBoardTactique::getInstance();
        decks.push_back(SchottenTottenBoardTactique::getClanDeck());
        decks.push_back(SchottenTottenBoardTactique::getTacticDeck());
        decks.push_back(SchottenTottenBoardTactique::getDiscardDeck());
    }
    SchottenTottenBoard *GameV1Tactique::getBoard() const { return SchottenTottenBoard::getInstance(); }

    GameV1Tactique::~GameV1Tactique() {
        SchottenTottenBoardTactique::freeInstance();
    }
    SchottenTottenBoard *GameV2::getBoard() const { return board; }
    SchottenTottenBoard *GameV2Tactique::getBoard() const { return board; }

}
