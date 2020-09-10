// IAJV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
class States 
{
	vector<<pair<Transition, States>> trans;
};

class StateMachine
{
	enum StatesEnum
	{
		ST_IDLE,
		ST_MOVING,
		ST_GATHER,
		ST_FILLING,
		ST_FLEE,
		ST_DEATH
	};
	States states;

	StateMachine() {}
	StateMachine(States s) {}

	void CreateStateMachine() 
	{
		States* idle = new States(ST_IDLE);
		States* moving = new States(ST_MOVING);
		Transition* transition = new Transition();
		idle->AddTransition(transition, moving);
	}

	void ProcessState()
	{

	}
};

class Transition
{
		void AddTransition();
		void Transition_isTrue();

};

class People
{
	enum Job
	{
		WOODWORKER,
		SOLDIER
	};
	int quantityInPocket;
	int maxQtInPocket;
	Job job;

	People() { job = Job::WOODWORKER;  quantityInPocket = 0;  maxQtInPocket = 100; }
	People(Job work, int pocket, int maxPocket) : job(work), quantityInPocket(pocket), maxQtInPocket(maxPocket) { }
};
// créer classe stateMachine , transition, character
// enum job ----> enum action pour chaque job , diff action globale

int main()
{	
	return 0;
}
