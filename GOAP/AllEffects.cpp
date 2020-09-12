#include "AllEffects.h"
#include <algorithm>

ChopWood::ChopWood() : Effect() {}
ChopWood::ChopWood(Condition cond) : Effect(cond) {}
void ChopWood::Process(People& p, GameState& gs) const { gs.nbTree -= 1; p.SetPocket(gs.maxQtInPocket); }
ChopWood::~ChopWood() {}

ReffineWood::ReffineWood() : Effect() {}
ReffineWood::ReffineWood(Condition cond) : Effect(cond) {}
void ReffineWood::Process(People& p, GameState& gs) const { gs.Stock -= gs.qtToBuild; gs.raffinedStock += gs.qtToBuild; }
ReffineWood::~ReffineWood() {}

BuildHouse::BuildHouse() : Effect() {}
BuildHouse::BuildHouse(Condition cond) : Effect(cond) {}
void BuildHouse::Process(People& p, GameState& gs) const { gs.curNbOfHouse += 1; gs.Stock -= gs.qtToBuild; }
BuildHouse::~BuildHouse() {}

Stock::Stock() : Effect() {}
Stock::Stock(Condition cond) : Effect(cond) {}
void Stock::Process(People& p, GameState& gs) const { gs.Stock += p.GetPocket(); p.SetPocket(0); }
Stock::~Stock() {}

LiberateVillager::LiberateVillager() : Effect() {}
LiberateVillager::LiberateVillager(Condition cond) : Effect(cond) {}
void LiberateVillager::Process(People& p, GameState& gs) const { gs.villagers.push_back(p); }
LiberateVillager::~LiberateVillager() {}

AssignVillager::AssignVillager() : Effect() {}
AssignVillager::AssignVillager(Condition cond) : Effect(cond) {}
void AssignVillager::Process(People& p, GameState& gs) const 
{
   /* auto it = std::find(gs.villagers.begin(), gs.villagers.end(), p);
    if (it != gs.villagers.end()) gs.villagers.erase(it);*/
}
AssignVillager::~AssignVillager() {}