// SchottenTottenBoard.cpp

#include "SchottenTottenBoard.h"

namespace Model
{
    SchottenTottenBoard *SchottenTottenBoard::instance = nullptr;
    SchottenTottenBoardTactique *SchottenTottenBoardTactique::instance = nullptr;

    void SchottenTottenBoard::update(const std::string &event) {
        if(event == "Piocher carte Clan"){

        }
    }
    void SchottenTottenBoardTactique::update(const std::string &event) {
        if(event == "Piocher carte Clan"){

        }
        if(event == "Piocher carte Tactique"){

        }
    }
}

