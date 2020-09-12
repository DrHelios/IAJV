#pragma once
#include "Action.h"
class Solver
{
	std::vector<Action*> listActions;
	int final_cost;
	People people;
	GameState gamestate;
public:
	Solver();
	Solver(int f_cost);
	Solver(int f_cost, People p, GameState gs);
	bool Planer(Action* action, std::vector<Action*>& list) const;
	void Add(Action* action);
	~Solver();
};

