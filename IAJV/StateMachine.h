#pragma once
#include "States.h"

class StateMachine
{
private:
	States* begin;
	States* current_states;
public:
	StateMachine() : begin(), current_states() {}
	StateMachine(States* start) : begin(start), current_states(start) { }
	~StateMachine() { delete begin; }

	States* GetBeginState() const { return begin; };

	States* GetCurrentState() const { return current_states; };

	void SetCurrentState(States* newCurrentState) { current_states = newCurrentState; }

	/*void ProcessState(const People &p, const GameState &gs)
	{
		
		for (const std::pair<const Transition*, States*> &list : current_states->GetTransitionList())
		{
			const  Transition* tmp = list.first;
			if (tmp->ReturnValue(p, gs))
			{
				SetCurrentState(list.second); 
				current_states = list.second;
			}
		}
	}*/
};

