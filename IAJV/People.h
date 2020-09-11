#pragma once
#include "StateMachine.h"
#include "Position.h"
#include "Helper.h"

struct GameState;

class People
{
private:
	Position pos{ 0.f,0.f };
	int quantityInPocket;
	std::string name;
	StateMachine* state_machine;
public:
	People() : quantityInPocket(0), name("Paul")  { }
	People(int pocket) : quantityInPocket(pocket), name("Paul") { }
	People(std::string param_name) : quantityInPocket(0), name(param_name) { }
	std::string GetName() const { return name; }
	Position GetPosition() const { return pos; }
	int GetQuantityInPocket() const { return quantityInPocket; }
	StateMachine* GetStateMachine() const { return state_machine; }
	void CreateStateMachine(States* state) { state_machine = new StateMachine(state); }
	void DestroyStateMachine() { delete state_machine; }
	void ProcessState(const GameState& gs);
};

