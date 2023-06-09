#pragma once

#include <iostream>
#include "../Model/Player/Human/Human.h"
#include "../Model/Game/Game.h"
#include "../Model/Border/Border.h"
#include "../Model/Combinaison/Combinaison.h"
namespace Model
{
    class GameControllerFactory {
    public:
        static Game* createGame(int v, const std::string& variante) {
            //Classe pour créer la game
            if (v == 1 && variante == "Classique") {
                return new GameV1(v, variante);
            } else if (v == 1 && variante == "Tactique") {
                return new GameV1Tactique(v, variante);
            } else if (v == 2 && variante == "Classique") {
                return new GameV2(v, variante);
            } else if (v == 2 && variante == "Tactique") {
                return new GameV2Tactique(v, variante);
            } else {
                // Gestion d'erreur ou valeur par défaut
                return nullptr;
            }
        }
    };

    class PlayerControllerFactory{
    public:
        static Player *createPlayer(const std::string &name, const std::vector<Card *> &hand = std::vector<Card*> (), const std::vector<Border *> &borders = std::vector<Border *>())
        {
            return new Human(name, hand, borders);
        }
    };

    class BorderControllerFactory{
    public:
        static Border *createBorder(int position, Player *owner = nullptr) {
            return new Border(position, owner);
        }
    };

    class CombinaisonControllerFactory {
    public:
        static Combinaison* createCombinaison(const std::vector<Card *>& hand) {
            std::vector<std::unique_ptr<Combinaison>> combinaisons; // Utilisation de std::unique_ptr pour la gestion automatique de la mémoire

            // Ajout des combinaisons à la liste
            combinaisons.push_back(std::make_unique<SuiteCouleur>());
            combinaisons.push_back(std::make_unique<Brelan>());
            combinaisons.push_back(std::make_unique<Couleur>());
            combinaisons.push_back(std::make_unique<Suite>());
            combinaisons.push_back(std::make_unique<Somme>());

            for(auto& combi : combinaisons){
                if(combi->estValide(hand))
                    return combi.release(); // Retourne l'objet Combinaison* et relâche la propriété de l'unique_ptr
            }

            return nullptr; // Aucune combinaison valide trouvée
        }
    };

//faut pas oublier de notifier l'eventManager à chaque action
    class Controller {
    private:
        int version_game;
        std::string variante_game;
        Player* player[4];  //je pense que c'est mieux de faire un std::vecteur plutot qu'un tableau
        Border* borders[9]; //idem
        Game* game;

    public:
        Controller(int v, const std::string& variante)
                : version_game(v), variante_game(variante)
        {
            game = GameControllerFactory::createGame(v, variante);
            player[0] = PlayerControllerFactory::createPlayer("Zak");
            player[1] = PlayerControllerFactory::createPlayer("Alexandre");
            player[2] = PlayerControllerFactory::createPlayer("Clément");
            player[3] = PlayerControllerFactory::createPlayer("Yue");
            for(int i =0; i<9; i++)
                borders[i] = BorderControllerFactory::createBorder(i);
;
        }
        //les 4 méthodes en dessus sont faites pour tester le main
        Player * getPlayer(const int idPlayer) {return player[idPlayer];}
        Border * getBorder(const int position) {return borders[position];}
        Game * getGame() {return game;}
        size_t getPlayerCount() {return sizeof(player);}
        bool canDrawClanCard(int idPlayer) const;
        bool canDrawTactic(int idPlayer) const;
        bool canPlayCard(int idPlayer, int borderPosition) const;
        bool canClaimBorder(int idPlayer, int borderPosition) const;
        int TacticCardCount(int idPlayer) const;
        ~Controller(){
            delete game;
        }
        /*void runGame()
        {
            std::cout << "Running the game..." << std::endl;

            // Perform game logic and actions

            // Notify events through the event manager
            eventManager->notifyEvent();
        }

        void registerEventListener(EventListener *listener)
        {
            eventManager->registerEventListener(listener);
        }*/
    };
}
