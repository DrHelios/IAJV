#pragma once
#include "Action.h"
class Solver
{
	std::vector<Action*> listActions;
public:
	bool Planer(Action* action, std::vector<Action*> &list) const
	{
		// il faut verifier que entre precontion et effect que l'enum est la meme
		// si une action a plusieurs precondition donc c'est un && ,et si des actions ont la m�me precondition c'est un ||
		//return un boolean en cas de branche qui �choue
		// utilis� la fonctions de mani�re r�cursive

	}
	void Add(Action* action) { listActions.push_back(action); }
};

