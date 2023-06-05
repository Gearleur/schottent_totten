#ifndef SCHOTTENT_TOTTEN_EVENTMANAGER_H
#define SCHOTTENT_TOTTEN_EVENTMANAGER_H

#include <iostream>
#include <vector>

namespace Model
{
    class EventListener
    {
    public:
        virtual void notify() = 0;
        virtual ~EventListener();
    };

    class EventManager : public EventListener
    {
    private:
        std::vector<EventListener *> eventListeners;

    public:
        void registerEventListener(EventListener *listener)
        {
            eventListeners.push_back(listener);
        }

        void notifyEvent()
        {
            std::cout << "Notifying all event listeners..." << std::endl;

            // Notify all registered event listeners
            for (auto listener : eventListeners)
            {
                listener->notify();
            }
        }
        void notify() override
        {
            std::cout << "Received notification from Game!" << std::endl;
            // Handle the notification event
        }
    };
}

#endif // SCHOTTENT_TOTTEN_EVENTMANAGER_H
