//
// Created by leeyu on 26/05/2023.
//

#ifndef SCHOTTENT_TOTTEN_COMBATMODE_H
#define SCHOTTENT_TOTTEN_COMBATMODE_H
#include "../Tactic.h"
namespace Model {
    class CombatMode: public Tactic {
    protected:
        Special tactic_card_type=Special::BattleModes;
    public:
        CombatMode(Numbered number, Color color): Tactic(number, color,Special::BattleModes){};
        virtual ~CombatMode() = default;
        virtual void showCard() const = 0;
        virtual  std::string getNom() const = 0;
        std::string getCardInfo() const = 0;
    };
    class Combatdeboue : public CombatMode {
    protected:
        const std::string name = "Combatdeboue";
    public:
        Combatdeboue(Numbered number=ONE, Color color=RED): CombatMode(number, color){};
        ~Combatdeboue() override = default;
        void showCard() const override;
        std::string getNom() const override {return name;};
        std::string getCardInfo() const override;
        void setColor(Color color) override  {this->color = color;};
    };
    class CollinMaillard : public CombatMode {
    protected:
        const std::string name = "CollinMaillard";
    public:
        CollinMaillard(Numbered number=ONE, Color color=RED): CombatMode(number, color){};
        ~CollinMaillard() override = default;
        void showCard() const override;
        std::string getNom() const override {return name;};
        std::string getCardInfo() const override;
    };
}



#endif //SCHOTTENT_TOTTEN_COMBATMODE_H