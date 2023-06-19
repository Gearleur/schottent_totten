#include <algorithm>
#include "Combinaison.h"

namespace Model
{
    Combinaison::~Combinaison() =default;
    bool SuiteCouleur::estValide(const std::vector<Card *> &hand)
    {
        // Vérifier si les trois cartes sont de la même couleur et de valeurs successives
        if (hand.size() < 3)
        {
            return false;
        }

        // Vérifier la couleur
        Color couleur = hand[0]->getColor();
        for (const Card *card : hand)
        {
            if (card->getColor() != couleur)
            {
                return false;
            }
        }

        // Vérifier les valeurs successives
        std::vector<int> valeurs;
        for (const Card *card : hand)
        {
            valeurs.push_back(static_cast<int>(card->getNumber()));
        }
        int num = valeurs.size();
        if(num==3){
        std::sort(valeurs.begin(), valeurs.end());
        return (valeurs[2] - valeurs[0] == 2 && valeurs[1] - valeurs[0] == 1);}
        else{
            std::sort(valeurs.begin(), valeurs.end());
            return (valeurs[3] - valeurs[0] == 3 &&valeurs[2] - valeurs[0] == 2 && valeurs[1] - valeurs[0] == 1);
        }
    }
    bool Brelan::estValide(const std::vector<Card *> &hand)
    {
        // Vérifier si les trois cartes ont la même valeur
        if (hand.size() < 3)
        {
            return false;
        }

        Numbered valeur = hand[0]->getNumber();
        for (const Card *card : hand)
        {
            if (card->getNumber() != valeur)
            {
                return false;
            }
        }
        return true;
    }

    bool Couleur::estValide(const std::vector<Card *> &hand) {
        // Vérifier si les trois cartes ont la même couleur
        if (hand.size() < 3)
        {
            return false;
        }

        Color couleur = hand[0]->getColor();
        for (const Card *card : hand)
        {
            if (card->getColor() != couleur)
            {
                return false;
            }
        }
        return true;
    }
    bool Suite::estValide(const std::vector<Card *> &hand)
    {
        // Vérifier si les trois cartes sont de valeurs successives et de couleurs quelconques
        if (hand.size() < 3)
        {
            return false;
        }

        std::vector<int> valeurs;
        for (const Card *card : hand)
        {
            valeurs.push_back(static_cast<int>(card->getNumber()));
        }
        std::sort(valeurs.begin(), valeurs.end());
        return (valeurs[2] - valeurs[0] == 2 && valeurs[1] - valeurs[0] == 1);
    }
    bool Somme::estValide(const std::vector<Card *> &hand)
    {
        // Vérifier si les trois cartes sont quelconques
        return hand.size() >= 3;
    }



}