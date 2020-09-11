#pragma once
#include "Condition.h"
#include "GameState.h"

class Precondition
{
	Condition condition;
public: 
	Precondition() : condition(P_DEFAULT) {}
	Precondition(Condition cond) : condition(cond) {}
	virtual bool Check(const People& p, const GameState& gs) const = 0;
	virtual ~Precondition() {}
};