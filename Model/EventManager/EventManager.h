#ifndef SCHOTTENT_TOTTEN_EVENTMANAGER_H
#define SCHOTTENT_TOTTEN_EVENTMANAGER_H

#include <iostream>
#include <vector>

namespace Model
{
    class Observer {
    public:
        virtual void update(const std::string& event) = 0;
    };

// Classe qui envoie des événements
    class EventManager {
    private:
        std::unordered_map<std::string, std::vector<Observer*>> observers;

    public:
        void subscribe(const std::string& event, Observer* observer) {
            observers[event].push_back(observer);
        }

        void emitEvent(const std::string& event) {
            if (observers.count(event) > 0) {
                for (Observer* observer : observers[event]) {
                    observer->update(event);
                }
            }
        }
    };

}

#endif // SCHOTTENT_TOTTEN_EVENTMANAGER_H
