//
// Created by leeyu on 26/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_RUSE_H
#define SCHOTTENT_TOTTEN_RUSE_H
#include "../Tactic.h"
#include "../../Card.h"

namespace Model {
    class Ruse : public Tactic {
    protected:
        Special tactic_card_type = Special::Tricks;
    public:
        Ruse(Numbered number, Color color) : Tactic(number, color, Special::Tricks) {};

        virtual ~Ruse() = default;

        virtual void showCard() const = 0;
    };

    class Traitre : public Ruse {
    protected:
        const std::string name = "Traitre";
    public:
        Traitre(Numbered number = ONE, Color color = RED) : Ruse(number, color) {};

        ~Traitre() override = default;

        void showCard() const override;

        void setColor(Color color) override { this->color = color; };
    };

    class ChasseurdeTete : public Ruse {
    protected:
        const std::string name = "Chasseur de Tête";
    public:
        ChasseurdeTete(Numbered number = ONE, Color color = RED) : Ruse(number, color) {};

        ~ChasseurdeTete() override = default;

        void showCard() const override;
    };

    class Stratege : public Ruse {
    protected:
        const std::string name = "Stratège";
    public:
        Stratege(Numbered number = ONE, Color color = RED) : Ruse(number, color) {};

        ~Stratege() override = default;

        void showCard() const override;
    };

    class Banshee: public Ruse {
    protected:
        const std::string name = "Banshee";
    public:
        Banshee(Numbered number = ONE, Color color = RED) : Ruse(number, color) {};

        ~Banshee() override = default;

        void showCard() const override;
    };


}

#endif //SCHOTTENT_TOTTEN_RUSE_H
