#pragma once
#include "Helper.h"
#include "Transition.h"
enum possibleStates { ST_IDLE, ST_MOVING, ST_GATHER, ST_FILLING, ST_FLEE, ST_DEATH };
enum craftHouseState { ST_CRAFTIDLE, ST_RAFFINE, ST_BUILD, ST_DONE };

class States
{
private:
	std::vector<const std::pair<Transition*, States*>> transistionList;
public:
	States() : transistionList() {}
	States(possibleStates state) : transistionList() {}
	~States()
	{
		for (auto t : transistionList)
		{
			delete t.first;
			if (t.second != nullptr) delete t.second;
		}
		transistionList.clear();
	}
	std::vector<const std::pair<Transition*, States*>> GetTransitionList()const  { return transistionList; }

	// Ajoute une transition à la liste des transition
	void AddTransition(Transition* transitionToUpdateStates ,States* targetStates) { transistionList.push_back(std::make_pair(transitionToUpdateStates, targetStates)); }
};

