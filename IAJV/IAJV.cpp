//// IAJV.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Helper.h"
#include "People.h"
#include"WorkerTransitions.h"
void CreateStateMachineForPeople(People &p)
{
	States* s = new States(possibleStates::ST_IDLE);
	s->AddTransition(new IdleToFinish(), possibleStates::ST_FINISH);
	s->AddTransition(new IdleToMoving(), possibleStates::ST_MOVING);
	s->AddTransition(new MovingToGather(), possibleStates::ST_GATHER);
	s->AddTransition(new GatherToMoving(), possibleStates::ST_MOVING);
	s->AddTransition(new MovingToFlee(), possibleStates::ST_FLEE);
	s->AddTransition(new FleeToDeath(), possibleStates::ST_DEATH);
	s->AddTransition(new FleeToGather(), possibleStates::ST_GATHER);
	s->AddTransition(new FleeToStock(), possibleStates::ST_FILLING);
	s->AddTransition(new FleeToMoving(), possibleStates::ST_MOVING);
	s->AddTransition(new MovingToStock(), possibleStates::ST_FILLING);
	s->AddTransition(new StockToIdle(), possibleStates::ST_IDLE);
	s->AddTransition(new IdleToCraftIdle(), craftHouseState::ST_CRAFTIDLE);
	s->AddTransition(new CraftIdleToMove(), craftHouseState::ST_MOVE);
	s->AddTransition(new MoveToReffine(), craftHouseState::ST_REFFINE);
	s->AddTransition(new ReffineToMove(), craftHouseState::ST_MOVE);
	s->AddTransition(new MoveToStock(), craftHouseState::ST_STOCKREF);
	s->AddTransition(new StockToCraftIdle(), craftHouseState::ST_CRAFTIDLE);
	s->AddTransition(new CraftIdleToBuild(), craftHouseState::ST_BUILD);
	s->AddTransition(new BuildToDone(), craftHouseState::ST_DONE);
	s->AddTransition(new DoneToIdle(), possibleStates::ST_IDLE);
	p.CreateStateMachine(s);
}

void DestroyStateMachineForPeople(People &p) { p.DestroyStateMachine(); }

GameState gs;
float x, y;

int main()
{
	x = 1;
	y = 1;
	gs.beginPos = { 0, 0 };
	gs.Stock = 0;
	gs.raffinedStock = 0;

#pragma region Paramétrage
	std::cout << "How much weight can I carry ?" << std::endl;
	std::cin >> gs.maxQtInPocket;

	std::cout << "How many houses do you want in our village ?" << std::endl;
	std::cin >> gs.numberOfHouses;

	std::cout << "Where is the forest ?" << std::endl;
	std::cout << "X ?" << std::endl;
	std::cin >> x;
	std::cout << "Y ?" << std::endl;
	std::cin >> y;
	gs.forestPos = { x, y };

	std::cout << "Where do I build the village ?" << std::endl;
	std::cout << "X ?" << std::endl;
	std::cin >> x;
	std::cout << "Y ?" << std::endl;
	std::cin >> y;
	gs.buildPos = { x, y };

	std::cout << "Where do I stock what I gather ?" << std::endl;
	std::cout << "X ?" << std::endl;
	std::cin >> x;
	std::cout << "Y ?" << std::endl;
	std::cin >> y;
	gs.stockPos = { x, y };

	std::cout << "Ok, let's go chief !" << std::endl;

#pragma endregion

	People p = People();
	CreateStateMachineForPeople(p);
	while (p.GetStateMachine()->GetCurrentState()->GetPossibleState() != possibleStates::ST_FINISH &&
		p.GetStateMachine()->GetCurrentState()->GetPossibleState() != possibleStates::ST_DEATH)
	{
		p.ProcessState(gs);
		while (std::cin.get() != '\n') {}
	}
	DestroyStateMachineForPeople(p);
	return 0;
}