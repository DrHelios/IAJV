#pragma once
#include "Action.h"
class Solver
{
	std::vector<Action*> listActions;
public:
	bool Planer(Action* action, std::vector<Action*> &list) const
	{
		// il faut verifier que entre precontion et effect que l'enum est la meme
		// si une action a plusieurs precondition donc c'est un && ,et si des actions ont la même precondition c'est un ||
		//return un boolean en cas de branche qui échoue
		// utilisé la fonctions de manière récursive

	}
	void Add(Action* action) { listActions.push_back(action); }
};

