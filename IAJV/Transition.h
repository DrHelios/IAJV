#pragma once
#include "GameState.h"

class People;

class Transition
{
	public:
		virtual bool ReturnValue(const People& p, const GameState& gm) const = 0;
};