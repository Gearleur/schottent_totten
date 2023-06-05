#pragma once
#include "../EventManager/EventManager.h"
#include "../Player/Player.h"
#include "../Board/Board.h"
namespace Model
{
    class Controller
    {
    private:
        EventManager eventManager;
        Player *player;

    public:
        bool drawControl();
        bool placeCardControl();
        bool claimBoarderControl();
        int TacticCardCount();
        void runGame()
        {
            std::cout << "Running the game..." << std::endl;

            // Perform game logic and actions

            // Notify events through the event manager
            eventManager.notifyEvent();
        }

        void registerEventListener(EventListener *listener)
        {
            eventManager.registerEventListener(listener);
        }
    };
}
