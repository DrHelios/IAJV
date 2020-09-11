#pragma once
#include "Precondition.h"

class PocketFull : Precondition 
{

public:
	virtual bool Check(const People& p, const GameState& gs) const { return (p.Pocket() == gs.maxQtInPocket); }
};

class WoodToBuild : Precondition
{
	virtual bool Check(const People& p, const GameState& gs) const { return (gs.Stock == gs.qtToBuild); }
};

class WorkerToBuild : Precondition
{
	virtual bool Check(const People& p, const GameState& gs) const { return (gs.villagers.size() >= gs.nbWorkerMax); }
};


