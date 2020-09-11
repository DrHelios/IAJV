#pragma once
#include "GoapAction.h"
#include "GameState.h"

using namespace std;

People* ppl = new People();
int pockets = ppl->woodPocket; //le passer en parametre a preconditions et effects


class ChopWood : public GoapAction
{
private:

	bool inRange = false;
	bool chopped = false;

public:
	float cost = 1;
	void reset() { chopped = true; }
	bool checkPrecondition() { woodworkerNb > 0 ; } //appeler la bonne fonction dans preconditionsVirtual
	bool perform() { totalWood += pockets; return true; }
	
	ChopWood() {}

};