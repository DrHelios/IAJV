#pragma once
#include "GoapAction.h"
#include "GameState.h"

using namespace std;

class ChopWood : public GoapAction
{
private:

	bool inRange = false;
	bool chopped = false;

public:
	float cost = 1;
	float targetX = 1, targetY = 1;
	void reset() { chopped = true; }
	bool isDone() { return chopped; }
	bool checkPrecondition() { woodworkerNb > 0 ; }
	bool perform() { totalWood += 200; return true; }
	bool requiresInRange() { return false; }
	bool isInRange() {
		return inRange;
	}


	ChopWood() {}

};