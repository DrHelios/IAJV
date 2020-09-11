#pragma once
#include "StateMachine.h"
#include "Helper.h"
#include "Position.h"
struct GameState;

class People
{
private:
	std::string name;
	Position pos{ 0.f,0.f };
	int quantityInPocket;
	StateMachine* state_machine;
public:
	People();
	People(int pocket);
	People(std::string param_name);
	std::string GetName() const;
	Position GetPosition() const;
	int GetQuantityInPocket() const;
	StateMachine* GetStateMachine();
	void CreateStateMachine(States* state);
	void DestroyStateMachine();
	int SetChanceToFlee() const;
	Position CalculateStep(Position beginPos, Position destinationPos) const;
	void ProcessState(GameState& gs);
	
};

