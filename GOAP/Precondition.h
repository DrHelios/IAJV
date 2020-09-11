#pragma once
#include "Condition.h"
#include "GameState.h"
#include "People.h"

class Precondition
{
private:
	Condition condition;
public: 
	Precondition() : condition(P_DEFAULT) {}
	Precondition(Condition cond) : condition(cond) {}
	int GetCondition() const { return condition; }
	virtual bool Check(const People& p, const GameState& gs) const = 0;
	virtual ~Precondition() {}
};