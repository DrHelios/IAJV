#pragma once
#include "GameState.h"
class People;

class Transition
{
private:
	int previousState;
public:
	Transition(int pvState) : previousState(pvState) {}
	int getPreviousState() const { return previousState; }
	virtual bool ReturnValue(const People& p, const GameState& gm) const = 0;
	virtual ~Transition() {}

};