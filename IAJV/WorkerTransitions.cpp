#include "WorkerTransitions.h"
#include "EnumState.h"
#include "People.h"

IdleToFinish::IdleToFinish() : Transition(possibleStates::ST_IDLE) {}
bool IdleToFinish::ReturnValue(const People& p, const GameState& gm) const { return (gm.curNbOfHouse == gm.numberOfHouses); }
IdleToFinish::~IdleToFinish() {}



IdleToMoving::IdleToMoving() : Transition(possibleStates::ST_IDLE) {}
bool IdleToMoving::ReturnValue(const People& p, const GameState& gm) const { return (gm.Stock < gm.qtToBuild); }
IdleToMoving::~IdleToMoving() {}



MovingToGather::MovingToGather() : Transition(possibleStates::ST_MOVING) {}
bool MovingToGather::ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.forestPos && p.GetQuantityInPocket() == 0); }
MovingToGather::~MovingToGather() {}



GatherToMoving::GatherToMoving() : Transition(possibleStates::ST_GATHER) {}
bool GatherToMoving::ReturnValue(const People& p, const GameState& gm) const { return (p.GetQuantityInPocket() == gm.maxQtInPocket); }
GatherToMoving::~GatherToMoving() {}



MovingToFlee::MovingToFlee() : Transition(possibleStates::ST_MOVING) {}
bool MovingToFlee::ReturnValue(const People& p, const GameState& gm) const { return (p.SetChanceToFlee() >= 50); }
MovingToFlee::~MovingToFlee() {}



FleeToDeath::FleeToDeath() : Transition(possibleStates::ST_FLEE) {}
bool FleeToDeath::ReturnValue(const People& p, const GameState& gm) const { return (p.SetChanceToFlee() >= 50); }
FleeToDeath::~FleeToDeath() {}


FleeToGather::FleeToGather() : Transition(possibleStates::ST_FLEE) {}
bool FleeToGather::ReturnValue(const People& p, const GameState& gm) const { return(p.GetPosition() == gm.forestPos); }
FleeToGather::~FleeToGather() {}


FleeToStock::FleeToStock() : Transition(possibleStates::ST_FLEE) {}
bool FleeToStock::ReturnValue(const People& p, const GameState& gm) const { return(p.GetPosition() == gm.stockPos); }
FleeToStock::~FleeToStock() {}


FleeToMoving::FleeToMoving() : Transition(possibleStates::ST_FLEE) {}
bool FleeToMoving::ReturnValue(const People& p, const GameState& gm) const { return (p.SetChanceToFlee() >= 50); }
FleeToMoving::~FleeToMoving() {}


MovingToStock::MovingToStock() : Transition(possibleStates::ST_MOVING) {}
bool MovingToStock::ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.stockPos && p.GetQuantityInPocket() != 0); }
MovingToStock::~MovingToStock() {}



StockToIdle::StockToIdle() : Transition(possibleStates::ST_FILLING) {}
bool StockToIdle::ReturnValue(const People& p, const GameState& gm) const { return (true); }
StockToIdle::~StockToIdle() {}



IdleToCraftIdle::IdleToCraftIdle() : Transition(possibleStates::ST_IDLE) {}
bool IdleToCraftIdle::ReturnValue(const People& p, const GameState& gm) const { return (gm.Stock >= gm.qtToBuild); }
IdleToCraftIdle::~IdleToCraftIdle() {}



CraftIdleToMove::CraftIdleToMove() : Transition(craftHouseState::ST_CRAFTIDLE) {}
bool CraftIdleToMove::ReturnValue(const People& p, const GameState& gm) const { return (gm.raffinedStock < gm.qtToBuild); }
CraftIdleToMove::~CraftIdleToMove() {}



MoveToReffine::MoveToReffine() : Transition(craftHouseState::ST_MOVE) {}
bool MoveToReffine::ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.stockPos && p.GetQuantityInPocket() == 0); }
MoveToReffine::~MoveToReffine() {}



ReffineToMove::ReffineToMove() : Transition(craftHouseState::ST_REFFINE) {}
bool ReffineToMove::ReturnValue(const People& p, const GameState& gm) const { return (p.GetQuantityInPocket() != 0); }
ReffineToMove::~ReffineToMove() {}



MoveToStock::MoveToStock() : Transition(craftHouseState::ST_MOVE) {}
bool MoveToStock::ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.buildPos); }
MoveToStock::~MoveToStock() {}



StockToCraftIdle::StockToCraftIdle() : Transition(craftHouseState::ST_STOCKREF) {}
bool StockToCraftIdle::ReturnValue(const People& p, const GameState& gm) const { return (true); }
StockToCraftIdle::~StockToCraftIdle() {}



CraftIdleToBuild::CraftIdleToBuild() : Transition(craftHouseState::ST_CRAFTIDLE) {}
bool CraftIdleToBuild::ReturnValue(const People& p, const GameState& gm) const { return (gm.raffinedStock >= gm.qtToBuild); }
CraftIdleToBuild::~CraftIdleToBuild() {}



BuildToDone::BuildToDone() : Transition(craftHouseState::ST_BUILD) {}
bool BuildToDone::ReturnValue(const People& p, const GameState& gm) const { return (true); }
BuildToDone::~BuildToDone() {}



DoneToIdle::DoneToIdle() : Transition(craftHouseState::ST_DONE) {}
bool DoneToIdle::ReturnValue(const People& p, const GameState& gm) const { return (true); }
DoneToIdle::~DoneToIdle() {}
