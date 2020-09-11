#pragma once
#include "effects.h"
#include "GameState.h"

using namespace std;

class CanBuild : public Effects
{
public:
	virtual string name() const { return "Il y a assez de bois pour construire"; }
	virtual ~CanBuild() {}
};
class CanChopWood : public Effects
{
public:
	virtual string name() const { return "Il y a assez de bucherons pour couper du bois"; }
	virtual ~CanChopWood() {}
};
class CanStoreInPockets : public Effects
{
public:
	virtual string name() const { return "Du bois peut encore etre stocké"; }
	virtual ~CanStoreInPockets() {}
};