#pragma once
#include "People.h"
#include "GameState.h"
class Transition
{
	public:
		virtual bool ReturnValue(const People &p, const GameState &gm) = 0;
};