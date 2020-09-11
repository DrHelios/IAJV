#pragma once
#include "Effect.h"

class ChopWood : Effect
{
public:
	ChopWood() : Effect() {}
	ChopWood(Condition cond) : Effect(cond) {}
	virtual void Process(const People& p, const GameState& gs) {  }

}; 

class BuildHousse: Effect
{
public:
	BuildHousse() : Effect() {}
	BuildHousse(Condition cond) : Effect(cond) {}
	virtual void Process(const People & p, const GameState & gs) {  }

};

class Stock : Effect
{
public:
	Stock() : Effect() {}
	Stock(Condition cond) : Effect(cond) {}
	virtual void Process(const People& p, const GameState& gs) {  }

};

