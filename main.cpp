#include <iostream>
#include "Model/Board/Board.h"
#include "Model/Border/Border.h"
#include "Model/Player/Player.h"
#include "Model/Card/Card.h"
#include "Model/Card/Clan/Clan.h"
#include "Model/Player/Human/Human.h"
#include <vector>
using namespace std;


int main() {
    //Create Vector of Clan Cards
    vector<Card *> clanCards;
    clanCards.push_back(new Clan(Numbered(0), Color(0)));
    clanCards.push_back(new Clan(Numbered(0), Color(1)));
    clanCards.push_back(new Clan(Numbered(0), Color(2)));
    clanCards.push_back(new Clan(Numbered(0), Color(3)));
    clanCards.push_back(new Clan(Numbered(0), Color(4)));
    clanCards.push_back(new Clan(Numbered(1), Color(5)));

    Human* player1 = new Human("Alexandre", clanCards);

    cout << player1->getName() << endl;
    cout << player1->getHand().size() << endl;

    player1->showHand();

    // Create 2 Human players


    return 0;
}
