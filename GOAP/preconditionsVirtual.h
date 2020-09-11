#pragma once
#include "preconditions.h"
#include "GameState.h"
#include "People.h"

using namespace std;

People *ppl = new People();
int pockets = ppl->woodPocket;

class EnoughWoodToBuild : public Preconditions
{
public:
	virtual bool name() const { return (totalWood >= maxWood); }
	virtual ~EnoughWoodToBuild() {}
};
class EnoughWoodworker : public Preconditions
{
public:
	virtual bool name() const { return woodworkerNb>0; }
	virtual ~EnoughWoodworker() {}
};
class ArePocketsFull : public Preconditions
{
public:
	virtual bool name() const { return pockets>=200; }
	virtual ~ArePocketsFull() {}
};