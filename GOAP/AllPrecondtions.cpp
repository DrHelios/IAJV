#include "AllPrecondtions.h"

PocketFull::PocketFull() : Precondition() {}
PocketFull::PocketFull(Condition cond) : Precondition(cond) {}
bool PocketFull::Check(const People& p, const GameState& gs) const { return (p.GetPocket() == gs.maxQtInPocket); }
PocketFull::~PocketFull(){}



WoodToBuild::WoodToBuild() : Precondition() {}
WoodToBuild::WoodToBuild(Condition cond) : Precondition(cond) {}
bool WoodToBuild::Check(const People& p, const GameState& gs) const { return (gs.Stock == gs.qtToBuild); }
WoodToBuild::~WoodToBuild(){}


ReffinedWoodToBuild::ReffinedWoodToBuild() : Precondition() {}
ReffinedWoodToBuild::ReffinedWoodToBuild(Condition cond) : Precondition(cond) {}
bool ReffinedWoodToBuild::Check(const People& p, const GameState& gs) const { return (gs.raffinedStock == gs.qtToBuild); }
ReffinedWoodToBuild::~ReffinedWoodToBuild(){}



WorkerToBuild::WorkerToBuild() : Precondition() {}
WorkerToBuild::WorkerToBuild(Condition cond) : Precondition(cond) {}
bool WorkerToBuild::Check(const People& p, const GameState& gs) const { return (gs.villagers.size() >= 1); }
WorkerToBuild::~WorkerToBuild() {}


GetTreesInForest::GetTreesInForest() : Precondition() {}
GetTreesInForest::GetTreesInForest(Condition cond) : Precondition(cond) {}
bool GetTreesInForest::Check(const People& p, const GameState& gs) const { return (gs.nbTree <= 0); }
GetTreesInForest::~GetTreesInForest() {}
