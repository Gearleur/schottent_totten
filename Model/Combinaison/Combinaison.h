#pragma once
#include <iostream>
#include <vector>
#include "../../Utils/enums.h"
#include "../Card/Card.h"
namespace Model
{
    // Classe de base abstraite pour les combinaisons
    class Combinaison
    {
    protected:
        int puissance; // puissance de la combinaison

    public:
        virtual bool estValide(const std::vector<Card *> &hand) = 0;
        const int getPuissance() const { return puissance; };
        virtual void setPuissance(int p) { puissance = p; };
        virtual void afficher() const = 0;
        virtual ~Combinaison();
    };

    // Classe pour la combinaison "Suite couleur"
    class SuiteCouleur : public Combinaison
    {
    public:
        void setPuissance(int p = 5) override
        {
            p = puissance;
        }
        bool estValide(const std::vector<Card *> &hand) override;
        void afficher() const override
        {
            std::cout << "Combinaison : Suite couleur" << std::endl;
        }
    };

    // Classe pour la combinaison "Brelan"
    class Brelan : public Combinaison
    {
    public:
        void setPuissance(int p = 4) override
        {
            p = puissance;
        }
        bool estValide(const std::vector<Card *> &hand) override;

        void afficher() const override
        {
            std::cout << "Combinaison : Brelan" << std::endl;
        }
    };

    // Classe pour la combinaison "Couleur"
    class Couleur : public Combinaison
    {
    public:
        void setPuissance(int p = 3) override
        {
            p = puissance;
        }
        bool estValide(const std::vector<Card *> &hand) override;

        void afficher() const override
        {
            std::cout << "Combinaison : Couleur" << std::endl;
        }
    };

    // Classe pour la combinaison "Suite"
    class Suite : public Combinaison
    {
    public:
        void setPuissance(int p = 2) override
        {
            p = puissance;
        }
        bool estValide(const std::vector<Card *> &hand) override;

        void afficher() const override
        {
            std::cout << "Combinaison : Suite" << std::endl;
        }
    };

    // Classe pour la combinaison "Somme"
    class Somme : public Combinaison
    {
    public:
        void setPuissance(int p = 1) override
        {
            p = puissance;
        }
        bool estValide(const std::vector<Card *> &hand) override;

        void afficher() const override
        {
            std::cout << "Combinaison : Somme" << std::endl;
        }
    };
}
