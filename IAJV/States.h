#pragma once
#include "Helper.h"
enum possibleStates { ST_IDLE, ST_MOVING, ST_GATHER, ST_FILLING,ST_CRAFT, ST_FLEE, ST_DEATH };
enum craftHouseState { ST_CRAFTIDLE, ST_RAFFINE, ST_BUILD, ST_DONE };

class Transition;

class States
{
private:
	std::vector<std::pair<Transition*, States*>> transistionList;
	possibleStates m_state;
public:
	States() : transistionList(), m_state(ST_IDLE) {}
	States(possibleStates state) : transistionList(), m_state(state) {}
	~States()
	{
		for (auto t : transistionList)
		{
			delete t.first;
			if (t.second != nullptr) delete t.second;
		}
		transistionList.clear();
	}
	std::vector<std::pair<Transition*, States*>> GetTransitionList()const  { return transistionList; }
	virtual void Process() const = 0;

	// Ajoute une transition à la liste des transition
	void AddTransition(Transition* transitionToUpdateStates,  States* targetStates) { transistionList.push_back(std::make_pair(transitionToUpdateStates, targetStates)); }
};

