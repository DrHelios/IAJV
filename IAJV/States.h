#pragma once
#include "Helper.h"
#include "EnumState.h"

class Transition;

class States
{
private:
	std::vector<std::pair<Transition*, int>> transistionList;
	int actualState;
public:
	States();
	States(possibleStates state);
	~States();
	std::vector<std::pair<Transition*, int>> GetTransitionList() const;
	int GetPossibleState() const;
	void SetPossibleState(int newActualState);
	// Ajoute une transition à la liste des transition
	void AddTransition(Transition* transitionToUpdateStates, int targetStates);
};