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
#include "../Board/Board.h"
// J'ai utilisé le design pattern factory, avec une classe mère abstraite et des classes filles singleton
namespace Model
{
    class Game
    {
    protected:
        int version;
        std::string variante;
        Board *instance;
        Game(int v, std::string var) : version(v), variante(var)
        {

            std::cout << "****** Game Constructor ******" << std::endl;
            std::cout << "Version: "<< getVersion() << std::endl;
            std::cout << "Variante: "<< getVariante() << std::endl;
        }

    public:
        virtual ~Game();

        int getVersion() const { return version; }
        std::string getVariante() const { return variante; }
        void setVersion(int v) { version = v; }
        void setVariante(std::string v) { variante = v; }
    };

    class GameV1 : public Game
    {
    private:
        GameV1(int v, std::string var) : Game(v, var) {}

    public:
        static GameV1 &getInstance(int v, std::string var)
        {
            static GameV1 instance(v, var);
            return instance;
        }
    };

    class GameV1Tactique : public Game
    {
    private:
        GameV1Tactique(int v, std::string var) : Game(v, var) {}

    public:
        static GameV1Tactique &getInstance(int v, std::string var)
        {
            static GameV1Tactique instance(v, var);
            return instance;
        }
    };

    class GameV2 : public Game
    {
    private:
        GameV2(int v, std::string var) : Game(v, var) {}

    public:
        static GameV2 &getInstance(int v, std::string var)
        {
            static GameV2 instance(v, var);
            return instance;
        }
    };

    class GameV2Tactique : public Game
    {
    private:
        GameV2Tactique(int v, std::string var) : Game(v, var) {}

    public:
        static GameV2Tactique &getInstance(int v, std::string var)
        {
            static GameV2Tactique instance(v, var);
            return instance;
        }
    };
}

#endif // SCHOTTENT_TOTTEN_GAME_H
