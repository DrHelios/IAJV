#include "AllPrecondtions.h"

PocketFull::PocketFull() : Precondition() {}
PocketFull::PocketFull(Condition cond) : Precondition(cond) {}
bool PocketFull::Check(const People& p, const GameState& gs) const { return (p.Pocket() == gs.maxQtInPocket); }
PocketFull::~PocketFull(){}



WoodToBuild::WoodToBuild() : Precondition() {}
WoodToBuild::WoodToBuild(Condition cond) : Precondition(cond) {}
bool WoodToBuild::Check(const People& p, const GameState& gs) const { return (gs.Stock == gs.qtToBuild); }
WoodToBuild::~WoodToBuild(){}


reffinedWoodToBuild::reffinedWoodToBuild() : Precondition() {}
reffinedWoodToBuild::reffinedWoodToBuild(Condition cond) : Precondition(cond) {}
bool reffinedWoodToBuild::Check(const People& p, const GameState& gs) const { return (gs.raffinedStock == gs.qtToBuild); }
reffinedWoodToBuild::~reffinedWoodToBuild(){}



WorkerToBuild::WorkerToBuild() : Precondition() {}
WorkerToBuild::WorkerToBuild(Condition cond) : Precondition(cond) {}
bool WorkerToBuild::Check(const People& p, const GameState& gs) const { return (gs.villagers.size() >= 1); }
WorkerToBuild::~WorkerToBuild() {}

