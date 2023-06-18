//
// Created by alexa on 10/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_GAME_H
#define SCHOTTENT_TOTTEN_GAME_H

// la class game est la classe principale du jeu
// c'est une classe singleton abstraite qui contient les fonctions principales du jeu
// Le jeu est un jeu tour par tour donc il faut une fonction qui permet de passer d'un joueur à l'autre
// cette classe abstraite engendre deux classe filles qui sont les deux modes de jeu
// un mode de jeu classique et un mode de jeu tactique
#include <string>
#include <iostream>
#include <memory>
#include "../Deck/ClanDeck/ClanDeck.h"
#include "../Deck/TacticDeck/TacticDeck.h"
#include "../Board/SchottenTottenBoard.h"
// J'ai utilisé le design pattern factory, avec une classe mère abstraite et des classes filles singleton
namespace Model
{
    class Game
    {
    protected:
        friend class Controller;
        int version;
        std::string variante;
        /*Board *board;*/ // attribut uniquement initialisé dans les classes filles, donc le board n'appartient pass à la classe mère
        std::vector<std::unique_ptr<Deck>> decks; // matrice de decks avec des pointeurs intelligents
        Game(int v, const std::string& var) : version(v), variante(var)
        {

        }

    public:
        virtual ~Game();

        int getVersion() const { return version; }
        std::string getVariante() const { return variante; }
        virtual Board *getBoard() const = 0;
    };

    class GameV1 : public Game
    {
    private:
        friend class GameControllerFactory;
        SchottenTottenBoard *board;
        GameV1(int v, const std::string& var);

    public:
        static GameV1 &getInstance(int v, const std::string& var)
        {
            static GameV1 instance(v, var);
            return instance;
        }
        Board *getBoard() const override;
        ~GameV1();
    };

    class GameV1Tactique : public Game
    {
    private:
        friend class GameControllerFactory;
        SchottenTottenBoard *board;
        GameV1Tactique(int v, const std::string& var);

    public:
        static GameV1Tactique &getInstance(int v, const std::string& var)
        {
            static GameV1Tactique instance(v, var);
            return instance;
        }
        Board *getBoard() const override;
        ~GameV1Tactique();
    };

    class GameV2 : public Game
    {
    private:
        friend class GameControllerFactory;
        SchottenTottenBoard *board;
        GameV2(int v, const std::string& var) : Game(v, var) {}

    public:
        static GameV2 &getInstance(int v, const std::string& var)
        {
            static GameV2 instance(v, var);
            return instance;
        }
        Board *getBoard() const override;
    };

    class GameV2Tactique : public Game
    {
    private:
        friend class GameControllerFactory;
        SchottenTottenBoard *board;
        GameV2Tactique(int v, const std::string& var) : Game(v, var) {}

    public:
        static GameV2Tactique &getInstance(int v, const std::string& var)
        {
            static GameV2Tactique instance(v, var);
            return instance;
        }
        Board *getBoard() const override;
    };
}

#endif // SCHOTTENT_TOTTEN_GAME_H