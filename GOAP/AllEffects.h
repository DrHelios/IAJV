#pragma once
#include "Effect.h"


class ChopWood : Effect
{
public:
	ChopWood();
	ChopWood(Condition cond);
	virtual void Process(const People& p, const GameState& gs);
	~ChopWood();

}; 

class ReffineWood : Effect
{
public:
	ReffineWood();
	ReffineWood(Condition cond);
	virtual void Process(const People& p, const GameState& gs);
	~ReffineWood();

};

class BuildHouse: Effect
{
public:
	BuildHouse() : Effect() {}
	BuildHouse(Condition cond) : Effect(cond) {}
	virtual void Process(const People & p, const GameState & gs) {  }	
	~BuildHouse();

};

class Stock : Effect
{
public:
	Stock() : Effect() {}
	Stock(Condition cond) : Effect(cond) {}
	virtual void Process(const People& p, const GameState& gs) {  }
	~Stock();
};

class GetVillager : Effect
{
public:
	GetVillager() : Effect() {}
	GetVillager(Condition cond) : Effect(cond) {}
	virtual void Process(const People& p, const GameState& gs) {  }
	~GetVillager();
};

class GetTreesInForest : Effect
{
public:
	GetTreesInForest() : Effect() {}
	GetTreesInForest(Condition cond) : Effect(cond) {}
	virtual void Process(const People& p, const GameState& gs) {  }
	~GetTreesInForest();
};


/*
int Stock, raffinedStock, curNbOfHouse, numberOfHouses, maxQtInPocket, nbWorkerMax,
		nbTree = 10000, qtToBuild = 1000;
*/