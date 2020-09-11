#pragma once
#include "States.h"

class StateMachine
{
private:
	States* begin;
	States* current_states;
public:
	StateMachine();
	StateMachine(States* start);
	~StateMachine();
	States* GetBeginState() const;
	States* GetCurrentState() const;
	void SetCurrentState(int newCurrentState);
};

