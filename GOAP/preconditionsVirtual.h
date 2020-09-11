#pragma once
#include "preconditions.h"
#include "GameState.h"

using namespace std;

class EnoughWoodToBuild : public Preconditions
{
public:
	virtual string name() const { return "Assez de bois pour construire"; }
	virtual ~EnoughWoodToBuild() {}
};
class EnoughWoodworker : public Preconditions
{
public:
	virtual string name() const { return "Assez de bucherons"; }
	virtual ~EnoughWoodworker() {}
};
class ArePocketsFull : public Preconditions
{
public:
	virtual string name() const { return "Les poches sont pleines"; }
	virtual ~ArePocketsFull() {}
};