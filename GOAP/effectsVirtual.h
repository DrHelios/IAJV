#pragma once
#include "effects.h"
#include "GameState.h"

using namespace std;

People* ppl = new People();
int pockets = ppl->woodPocket;

class CanBuild : public Effects
{
public:
	virtual bool name() const { housesNb++; return true; }
	virtual ~CanBuild() {}
};
class CanChopWood : public Effects
{
public:
	virtual bool name() const { totalWood += pockets;  return true; }
	virtual ~CanChopWood() {}
};
class CanStoreInPockets : public Effects
{
public:
	virtual bool name() const { pockets += 200; return true; }
	virtual ~CanStoreInPockets() {}
};