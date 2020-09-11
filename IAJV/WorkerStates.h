#pragma once
#include "States.h"

class IdleState : public States {

public:
	IdleState() : States() {}
	IdleState(possibleStates state) : States(state) {}
	virtual void Process() const { std::cout << "idle" << std::endl; }
};

class MoveState : public States {

public:
	MoveState() : States() {}
	MoveState(possibleStates state) : States(state) {}
	virtual void Process() const { std::cout << "moving" << std::endl; }
};

class GatherState : public States {

public:
	GatherState() : States() {}
	GatherState(possibleStates state) : States(state) {}
	virtual void Process() const { std::cout << "gather" << std::endl; }
};

class StockState : public States {

public:
	StockState() : States() {}
	StockState(possibleStates state) : States(state) {}
	virtual void Process() const { std::cout << "stock" << std::endl; }
};

class CraftState : public States {

public:
	CraftState() : States() {}
	CraftState(possibleStates state) : States(state) {}
	virtual void Process() const { std::cout << "craft" << std::endl; }
};

class DeathState : public States {

public:
	DeathState() : States() {}
	DeathState(possibleStates state) : States(state) {}
	virtual void Process() const { std::cout << "death" << std::endl; }
};