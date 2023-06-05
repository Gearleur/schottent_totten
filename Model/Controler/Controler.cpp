#include "Controler.h"

namespace Model
{
    bool Controller::drawControl()
    {
        return player->getHand().size() < 6;
    }

    bool Controller::placeCardControl()
    {
        return true;
    }

    bool Controller::claimBoarderControl() // vérifier qu'il y a le nombre de carte max des deux côtés et que la combinaison est la plus forte
    {
        return true;
    }
}
