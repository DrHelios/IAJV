#pragma once
#include <vector>
#include <string>
#include "Precondition.h"
#include "Effect.h"
class Action
{
	std::string m_name;
	std::vector<Precondition*> preconditions;
	std::vector<Effect*> effects;
	int m_cost;
public:
	Action() : m_name("default"), preconditions(), effects(), m_cost(0)  {}
	Action(std::string name, int cost) : m_name(name), m_cost(cost), preconditions(), effects() {}
	void AddPrecondition(Precondition* precond) { preconditions.push_back(precond); }
	void AddEffect(Effect* eff) { effects.push_back(eff); }

};

