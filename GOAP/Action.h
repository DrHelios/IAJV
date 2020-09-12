#pragma once
#include <vector>
#include <string>
#include "Precondition.h"
#include "Effect.h"
class Action
{
private:
	std::string m_name;
	std::vector<Precondition*> preconditions;
	std::vector<Effect*> effects;
	int m_cost;
public:
	Action();
	Action(std::string name, int cost);
	void AddPrecondition(Precondition* precond);
	void AddEffect(Effect* eff);
	int GetCost() const;
	std::vector<Precondition*> GetPrecontionList() const;
	std::vector<Effect*> GetEffectList() const;
	~Action();

};

