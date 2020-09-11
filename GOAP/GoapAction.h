#pragma once
#include <iostream>
#include <string.h>
#include "preconditionsVirtual.h"
#include "effectsVirtual.h"

using namespace std;

class GoapAction
{
private:

	bool inRange = false;

public:
	float cost = 1;
	float targetX = 1, targetY = 1;
	void reset();
	bool isDone();
	bool checkPrecondition();
	bool perform();
	bool requiresInRange();
	bool isInRange() {
		return inRange;
	}


	GoapAction() {}



};