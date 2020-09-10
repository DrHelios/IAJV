#pragma once
#include "StateMachine.h"
class People
{
private:
	Position pos{ 0.f,0.f };
	int quantityInPocket;
	StateMachine* state_machine;
public:
	People() { quantityInPocket = 0; }
	People(int pocket) :  quantityInPocket(pocket) { }
	Position GetPosition() const { return pos; }
	int GetQuantityInPocket() const { return quantityInPocket; }
	StateMachine* GetStateMachine() const { return state_machine; }
	void CreateStateMachine(States* state) { state_machine = new StateMachine(state); }
	void DestroyStateMachine() { delete state_machine; }
};

