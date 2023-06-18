//
// Created by alexa on 10/05/2023.
//

#include "Game.h"

namespace Model
{
    Game::~Game()
    {
    }
    GameV1::GameV1(int v, const std::string& var) : Game(v, var)
    {
        board = SchottenTottenBoard::getInstance();
        board->createClanDeck();
        decks.push_back(std::unique_ptr<Deck>(board->getClanDeck()));
    }
    Board *GameV1::getBoard() const { return board; }
    GameV1::~GameV1(){
        delete board;
    }
    GameV1Tactique::GameV1Tactique(int v, const std::string& var) : Game(v, var)
    {
        board = SchottenTottenBoard::getInstance();
        board->createClanDeck();
        board->createTacticDeck();
        board->createDiscardDeck();
        decks.push_back(std::unique_ptr<Deck>(board->getClanDeck()));
        decks.push_back(std::unique_ptr<Deck>(board->getTacticDeck()));
        decks.push_back(std::unique_ptr<Deck>(board->getDiscardDeck()));
    }
    Board *GameV1Tactique::getBoard() const { return board; }

    GameV1Tactique::~GameV1Tactique() {
        delete board;
    }
    Board *GameV2::getBoard() const { return board; }
    Board *GameV2Tactique::getBoard() const { return board; }

}