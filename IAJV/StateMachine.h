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

};

