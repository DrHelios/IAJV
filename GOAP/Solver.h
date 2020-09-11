#pragma once
#include "Action.h"
class Solver
{
	std::vector<Action*> listActions;
public:
	std::vector<Action*> Planer(Action* action) const
	{
		// il faut verifier que entre precontion et effect que l'enum est la meme
		// si une action a plusieurs precondition donc c'est un && ,et si des actions ont la même precondition c'est un ||
		// utilisé la fonctions de manière récursive
	}
};

