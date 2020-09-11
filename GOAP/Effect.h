#pragma once
#include "Condition.h"
#include"GameState.h"

class Effect
{
	Condition condition;
public:
	Effect() : condition(P_DEFAULT) {}
	Effect(Condition cond) : condition(cond) {}
	virtual void Process(const People& p, const GameState& gs) const = 0;
	virtual ~Effect() {}
};

