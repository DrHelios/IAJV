#pragma once
#include "GameState.h"
class People;

class Transition
{
public:
	int previousState;
	Transition(int pvState) : previousState(pvState) {}
	virtual bool ReturnValue(const People& p, const GameState& gm) const = 0;
	virtual ~Transition() {}

};