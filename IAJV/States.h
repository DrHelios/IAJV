#pragma once
#include "Helper.h"
#include "EnumState.h"

class Transition;

class States
{
private:
	std::vector<std::pair<Transition*, int>> transistionList;
public:
	int actualState;
	States();
	States(possibleStates state);
	~States();
	std::vector<std::pair<Transition*, int>> GetTransitionList() const;

	int GetPossibleState() const;
	// Ajoute une transition à la liste des transition
	void AddTransition(Transition* transitionToUpdateStates, int targetStates);
};