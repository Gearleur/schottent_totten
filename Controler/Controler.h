#pragma once

#include <iostream>
#include "../Model/Player/Human/Human.h"
#include "../Model/Game/Game.h"
#include "../Model/Border/Border.h"
#include "../Model/Combinaison/Combinaison.h"
#include "../Model/EventManager/EventManager.h"
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
        std::vector<Player*> observers;  //je pense que c'est mieux de faire un std::vecteur plutot qu'un tableau
        Border* borders[9]; //idem
        Game * game;
        EventManager eventManager;
    public:
        Controller(int v, const std::string& variante)
                : version_game(v), variante_game(variante)
        {
            game = GameControllerFactory::createGame(v, variante);
            observers.push_back(new Human("J1", std::vector<Card*> (), std::vector<Border*> ()));
            observers.push_back(new Human("J2", std::vector<Card*> (), std::vector<Border*> ()));
            for(size_t i = 0; i<9; i++)
                borders[i] = new Border((int)i);
        }
        //les 4 méthodes en dessus sont faites pour tester le main
        //getters sans modifications
        const Player * getPlayer(const int idPlayer) const {return observers[idPlayer];}
        const Border * getBorder(const int position) const {return borders[position];}
        const Game * getGame() const {return game;}
        //getters avec modifications
        Player * getPlayer(const int idPlayer) {return observers[idPlayer];}
        Border * getBorder(const int position) {return borders[position];}
        Game * getGame() {return game;}
        SchottenTottenBoard* getBoard() {return SchottenTottenBoard::getInstance();}
        size_t getPlayerCount() {return observers.size();}
        bool canDrawClanCard(int idPlayer) const;
        bool canDrawTactic(int idPlayer) const;
        bool canPlayCard(int idPlayer, int borderPosition) const;
        bool canClaimBorder(int idPlayer, int borderPosition) const;
        int TacticCardCount(int idPlayer) const;
        ~Controller(){
            delete game;
            for(const auto i : observers)
                delete i;
            for(const auto i : borders)
                delete i;
        }
        /*
        void init() {
            game = GameControllerFactory::createGame(version_game, variante_game);
            for(int i =0; i<2; i++)
                player[i] = PlayerControllerFactory::createPlayer(std::to_string(i));
            for(int i =0; i<9; i++)
                borders[i] = BorderControllerFactory::createBorder(i);
        }

        void start() {
            while (!game->isGameFinished()) {
                performAction();
            }
            std::cout << "Game finished!" << std::endl;
        }

        void performAction() {
            int currentPlayerIndex = game->getCurrentPlayerIndex();
            Player* currentPlayer = player[currentPlayerIndex];
            Border* currentBorder = nullptr;
            Combinaison* combinaison = nullptr;

            // Obtenir l'action du joueur (à implémenter)
            std::string action = currentPlayer->getAction();

            if (action == "PlayCard") {
                Card* card = currentPlayer->getCardToPlay();
                currentBorder = currentPlayer->selectBorder(borders);

                // Vérifier si la carte peut être jouée
                if (currentBorder && card) {
                    combinaison = CombinaisonControllerFactory::createCombinaison(currentBorder->getCards());

                    // Vérifier si la combinaison est valide
                    if (combinaison) {
                        currentPlayer->removeCard(card);
                        currentBorder->addCard(card);
                        game->updateGameStatus();
                        eventManager.notifyEvent("CardPlayed"); // Notifier l'événement "CardPlayed"
                    } else {
                        // Combinaison invalide
                        std::cout << "Invalid combination!" << std::endl;
                    }
                } else {
                    // Border invalide ou carte non sélectionnée
                    std::cout << "Invalid border or no card selected!" << std::endl;
                }
            } else if (action == "DrawCard") {
                currentPlayer->drawCard(game->getDeck());
                game->updateGameStatus();
                eventManager.notifyEvent("CardDrawn"); // Notifier l'événement "CardDrawn"
            } else {
                // Action invalide
                std::cout << "Invalid action!" << std::endl;
            }
        }
         */
    };
}
