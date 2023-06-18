#pragma once

#include <iostream>
#include <vector>
#include "../Player/Player.h"
namespace Model
{
    class Player;
    /*class Observer {
    public:
        virtual void update(const std::string& event) = 0;
    };*/

// Classe qui envoie des événements
    class EventManager {
    private:
        std::vector<Player*> observers;
    public:
        void RegisterObserver(Player* player) {
            observers.push_back(player);
        }

        void UnregisterObserver(Player* player) {
            // Implémentez ici la logique pour supprimer un observateur de la liste
        }

        /*void NotifyPlayers(const std::string& message) {
            for (auto observer : observers) {
                observer->Notify(message);
            }
        }*/
    };

}