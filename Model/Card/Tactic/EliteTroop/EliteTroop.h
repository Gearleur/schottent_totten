//
// Created by leeyu on 26/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_ELITETROOP_H
#define SCHOTTENT_TOTTEN_ELITETROOP_H
#include "../Tactic.h"

namespace Model {
    class EliteTroop : public Tactic {
    protected:
        Special tactic_card_type=Special::EliteTroops;
    public:
        EliteTroop(Numbered number, Color color): Tactic(number, color,Special::EliteTroops){};
        virtual ~EliteTroop() = default;
        virtual void showCard() const = 0;
        virtual std::string getNom() const = 0;
        virtual std::string getCardInfo() const = 0;

    };
    class Joker : public EliteTroop {
    protected:
        const std::string name = "Joker";
    public:
        Joker(Numbered number=ONE, Color color=RED): EliteTroop(number, color){};
        ~Joker() override = default;
        void showCard() const override;
        std::string getNom() const override {return name;};
        std::string getCardInfo() const override;
        void setColor(Color color) override  {this->color = color;};
        void setNumber(Numbered number) override  {this->number = number;};
    };

    class Espion : public EliteTroop {
    protected:
        const std::string name = "Espion";
    public:
        Espion(Numbered number=SEVEN, Color color=RED): EliteTroop(number, color){};
        ~Espion() override = default;
        void showCard() const override;
        std::string getNom() const override {return name;};
        std::string getCardInfo() const override;
        void setColor(Color color) override  {this->color = color;};
    };

    class Portebouclier : public EliteTroop {
    protected:
        const std::string name = "Portebouclier";
    public:
        Portebouclier(Numbered number=ONE, Color color=RED): EliteTroop(number, color){};
        ~Portebouclier() override = default;
        void showCard() const override;
        std::string getNom() const override {return name;};
        std::string getCardInfo() const override;
        void setColor(Color color) override  {this->color = color;};
        void choseNumber(Numbered number);
    };
};

#endif //SCHOTTENT_TOTTEN_ELITETROOP_H