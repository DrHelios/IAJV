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

	States* GetBeginState()const { return begin; };

	States* GetCurrentState()const { return current_states; };

	void SetCurrentState(States* newCurrentState) { current_states = newCurrentState; }

	void ProcessState(const People &p, const GameState &gs)
	{
		States* currentState = this->GetCurrentState();
		for (const std::pair<Transition*, States*> &list : currentState->GetTransitionList())
		{
			Transition* tmp = list.first;
			if (tmp->ReturnValue(p, gs))
			{
				SetCurrentState(list.second);
			}
		}
	}
};

