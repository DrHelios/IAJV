#pragma once
#include "Action.h"
class Solver
{
	std::vector<Action*> listActions;
	int final_cost;
	People people;
	GameState gamestate;
public:
	Solver() : final_cost(100), listActions(){}
	Solver(int f_cost) : final_cost(0), listActions() {}
	Solver(int f_cost, People p , GameState gs) : final_cost(0), people(p), gamestate(gs) ,  listActions() {}
	bool Planer(Action* action, std::vector<Action*> &list) const
	{
		// il faut verifier que entre precontion et effect que l'enum est la meme
		// si une action a plusieurs precondition donc c'est un && ,et si des actions ont la même precondition c'est un ||
		//return un boolean en cas de branche qui échoue
		// utilisé la fonctions de manière récursive
		int current_cost = 0;
		std::vector<Action*> list_tmp;
		for (auto& a : listActions) 
		{
			for (auto& e : a->GetEffectList())
			{
				for (auto& p : a->GetPrecontionList())
				{
					if (e->GetCondition() == p->GetCondition())
					{
						if (p->Check(people, gamestate))
						{
							list_tmp.push_back(a);
							current_cost += a->GetCost();
						}
					}
				}
			}
			if(final_cost > current_cost)
				list = list_tmp;
		}
	}
	void Add(Action* action) { listActions.push_back(action); }
	~Solver() { listActions.clear(); }
};

