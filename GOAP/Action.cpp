#include "Action.h"
Action::Action() : m_name("default"), preconditions(), effects(), m_cost(0) {}
Action::Action(std::string name, int cost) : m_name(name), m_cost(cost), preconditions(), effects() {}
void Action::AddPrecondition(Precondition* precond) { preconditions.push_back(precond); }
void Action::AddEffect(Effect* eff) { effects.push_back(eff); }
int Action::GetCost() const { return m_cost; }
std::vector<Precondition*>Action::GetPrecontionList() const { return preconditions; }
std::vector<Effect*> Action::GetEffectList() const { return effects; }
Action::~Action() { preconditions.clear(); effects.clear(); }