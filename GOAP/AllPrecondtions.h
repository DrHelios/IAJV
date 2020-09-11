#pragma once
#include "Precondition.h"

class PocketFull : Precondition 
{

public:
	PocketFull() : Precondition() {}
	PocketFull(Condition cond) : Precondition(cond) {}
	virtual bool Check(const People& p, const GameState& gs) const { return (p.Pocket() == gs.maxQtInPocket); }
};

class WoodToBuild : Precondition
{
public:
	WoodToBuild() : Precondition() {}
	WoodToBuild(Condition cond) : Precondition(cond) {}
	virtual bool Check(const People& p, const GameState& gs) const { return (gs.Stock == gs.qtToBuild); }
};

class WorkerToBuild : Precondition
{
public:
	WorkerToBuild() : Precondition() {}
	WorkerToBuild(Condition cond) : Precondition(cond) {}
	virtual bool Check(const People& p, const GameState& gs) const { return (gs.villagers.size() >= gs.nbWorkerMax); }
};


