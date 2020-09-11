#include "AllEffects.h"

ChopWood::ChopWood() : Effect() {}
ChopWood::ChopWood(Condition cond) : Effect(cond) {}
void ChopWood::Process(const People& p, const GameState& gs) { gs.nbTree -= 1; p.quantityInPocket = gs.maxQtInPocket; }
ChopWood::~ChopWood();


ReffineWood::ReffineWood() : Effect() {}
ReffineWood::ReffineWood(Condition cond) : Effect(cond) {}
void ReffineWood::Process(const People& p, const GameState& gs) { gs.Stock -= gs.qtyToBuild; gs.raffinedStock += gs.qtToBuild; }
ReffineWood::~ReffineWood();


BuildHouse::BuildHouse() : Effect() {}
BuildHouse::BuildHouse(Condition cond) : Effect(cond) {}
void BuildHouse::Process(const People& p, const GameState& gs) { gs.curNbOfHouse += 1; gs.Stock -= gs.qtToBuild; }
BuildHouse::~BuildHouse();


Stock::Stock() : Effect() {}
Stock(Condition cond) : Effect(cond) {}
void Stock::Process(const People& p, const GameState& gs) { gs.Stock += p.quantityInPocket; p.quantityInPocket = 0; }
Stock::~Stock();


GetVillager::GetVillager() : Effect() {}
GetVillager::GetVillager(Condition cond) : Effect(cond) {}
void GetVillager::Process(const People& p, const GameState& gs) { return gs.villagers; }
GetVillager::~GetVillager();


GetTreesInForest::GetTreesInForest() : Effect() {}
GetTreesInForest::GetTreesInForest(Condition cond) : Effect(cond) {}
void GetTreesInForest::Process(const People& p, const GameState& gs) { return gs.nbTree; }
GetTreesInForest::~GetTreesInForest();