//
// Created by leeyu on 19/06/2023.
//

#ifndef SCHOTTENT_TOTTEN_HANDLE_H
#define SCHOTTENT_TOTTEN_HANDLE_H
#include "../Model/Player/Player.h"
#include "../Model/Board/Board.h"
#include "../Model/Board/Board.h"
#include "../Controler/Controler.h"
#include "../Model/Player/Player.h"
#include "../Model/Board/SchottenTottenBoard.h"
#include "../Model/Card/Clan/Clan.h"
#include "../Model/Card/Tactic/CombatMode/CombatMode.h"
#include "../Model/Card/Tactic/Ruse/Ruse.h"
void setValuesTacticCards(Model::Player *pPlayer, Model::Board *pBoard, const std::vector<Model::Card*> *borderSide, int borderChoice, Model::Controller *controller);
bool handledeclare(Model::Player *pPlayer, Model::Board *pBoard, int borderChoice, Model::Controller *controller);

void handleTraitre(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller);
void handleStratege(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller);
bool handlepiocheTactic(Model::Player * pPlayer, Model::Board *pBoard, size_t max_card);
bool handlepioche(Model::Player *pPlayer, Model::Board *pBoard, size_t max_card);
void handleChasseurdeTete(Model::Player * pPlayer, Model::Board *pBoard, size_t max);
void handleCombatdeboue(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice, Model::Controller *controller);
bool handleCollinMaillard(Model::Player *pPlayer, Model::Player *adversaire, Model::Board *pBoard, int borderPosition, Model::Controller *controller);
void handleBansheePlayer(Model::Player *pPlayer, std::vector<Model::Card*> borderSide, Model::Board *pBoard, Model::Controller *controller);
bool handleplaycard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice);
void handleBanshee(Model::Player *pPlayer, Model::Board *pBoard, Model::Controller *controller);
bool handleplaytacticalcard(Model::Player *pPlayer, Model::Board *pBoard, int cardChoice, int borderChoice, Model::Controller *controller);
void handleJoker(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller);
void handleEspion(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller);
void handlePorteBouclier(Model::Player *pPlayer, Model::Board *pBoard, Model::Card *card, Model::Controller *controller);
void setValuesTacticCards(Model::Player *pPlayer, Model::Board *pBoard, const std::vector<Model::Card*> *borderSide, int borderChoice, Model::Controller *controller);
bool handledeclare(Model::Player *pPlayer, Model::Board *pBoard, int borderChoice, Model::Controller *controller);
#endif //SCHOTTENT_TOTTEN_HANDLE_H
