#pragma once
#include "GameState.h"
#include "People.h"
#include "Condition.h"

class Effect
{
private:
	Condition condition;
public:
	Effect() : condition(P_DEFAULT) {}
	Effect(Condition cond) : condition(cond) {}
	int GetCondition() const { return condition; }
	virtual void Process(People& p, GameState& gs) const = 0;
	virtual ~Effect() {}
};

