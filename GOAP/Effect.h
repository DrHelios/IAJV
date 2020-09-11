#pragma once
#include "Condition.h"
#include "GameState.h"
#include "People.h"

class Effect
{
private:
	Condition condition;
public:
	Effect() : condition(P_DEFAULT) {}
	Effect(Condition cond) : condition(cond) {}
	int GetCondition() const { return condition; }
	virtual void Process(const People& p, const GameState& gs) const = 0;
	virtual ~Effect() {}
};

