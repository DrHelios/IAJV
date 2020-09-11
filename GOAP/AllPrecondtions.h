#pragma once
#include "Precondition.h"

class PocketFull : Precondition 
{

public:
	PocketFull();
	PocketFull(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~PocketFull();
};

class WoodToBuild : Precondition
{
public:
	WoodToBuild();
	WoodToBuild(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~WoodToBuild();
};

class reffinedWoodToBuild : Precondition
{
public:
	reffinedWoodToBuild();
	reffinedWoodToBuild(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~reffinedWoodToBuild();
};


class WorkerToBuild : Precondition
{
public:
	WorkerToBuild();
	WorkerToBuild(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~WorkerToBuild();
};


