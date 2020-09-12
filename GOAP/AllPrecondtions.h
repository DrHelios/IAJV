#pragma once
#include "Precondition.h"

class PocketFull : public Precondition 
{

public:
	PocketFull();
	PocketFull(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~PocketFull();
};

class WoodToBuild : public Precondition
{
public:
	WoodToBuild();
	WoodToBuild(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~WoodToBuild();
};

class ReffinedWoodToBuild : public Precondition
{
public:
	ReffinedWoodToBuild();
	ReffinedWoodToBuild(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~ReffinedWoodToBuild();
};

class WorkerToBuild : public Precondition
{
public:
	WorkerToBuild();
	WorkerToBuild(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~WorkerToBuild();
};

class GetTreesInForest : public Precondition
{
public:
	GetTreesInForest();
	GetTreesInForest(Condition cond);
	virtual bool Check(const People& p, const GameState& gs) const;
	~GetTreesInForest();
};
