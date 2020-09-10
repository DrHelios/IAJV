// IAJV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Position {
	float x, y;
	bool operator==(const Position& p) { return (x == p.x && y == p.y); }
};

struct GameState
{
	int Stock, raffinedStock, numberOfHouses,maxQtInPocket, qtToBuild = 1000;
	Position beginPos, forestPos, stockPos, buildPos;
};

class Transition
{ 
	public:
		Transition() {}
		virtual bool ReturnValue(People p, GameState gm) = 0;
};

#pragma region Transitions
class IdleToMove : Transition
{
	public:
		bool ReturnValue(People p, GameState gm) { return (gm.Stock != gm.qtToBuild);}
};

class MoveToGather : Transition
{
	public:
		bool ReturnValue(People p, GameState gm) { return (p.GetPosition() == gm.forestPos); }
};

class GatherToMove : Transition
{
	public:
		bool ReturnValue(People p, GameState gm) { return (p.GetQuantityInPocket() == gm.maxQtInPocket); }
};

class MoveToStock : Transition
{
	public:
		bool ReturnValue(People p, GameState gm) { return (p.GetPosition() == gm.stockPos); }
};

class StockToIdle : Transition
{
	public:
		bool ReturnValue(People p, GameState gm) { return (p.GetPosition() == gm.beginPos); }
};

class IdleToCrafthouse : Transition
{
	public:
		bool ReturnValue(People p, GameState gm) { return (gm.Stock == gm.qtToBuild); }
};

#pragma endregion 
enum possibleStates { ST_IDLE, ST_MOVING, ST_GATHER, ST_FILLING, ST_FLEE, ST_DEATH };
enum craftHouseState {ST_CRAFTIDLE, ST_RAFFINE, ST_BUILD, ST_DONE};

class States 
{
	private:
		std::vector<std::pair<Transition*, States*>> transistionList;
	public: 
		States() : transistionList() {}
		States(possibleStates state) : transistionList() {}
		~States() 
		{ 
			for (auto t : transistionList) 
			{
				delete t.first;
				if(t.second != nullptr) delete t.second;
			} 
			transistionList.clear();
		}
		std::vector<std::pair<Transition*, States*>> GetTransitionList() { return transistionList; }

		// Ajoute une transition à la liste des transition
		void AddTransition(Transition* transitionToUpdateStates, States* targetStates) { transistionList.push_back(std::make_pair(transitionToUpdateStates, targetStates)); }
};

class StateMachine
{
	private:
		States* begin;
		States* current_states;
	public:
		StateMachine() : begin(), current_states() {}
		StateMachine(States* start) : begin(start),current_states(start) { }
		~StateMachine() { delete begin; }
	
		States* GetBeginState() { return begin; };

		States* GetCurrentState() {	return current_states; };

		States* SetCurrentState(States* newCurrentState) { current_states = newCurrentState; }

		void ProcessState()
		{
			States* currentState = this->GetCurrentState();
			for (auto list : currentState->GetTransitionList())
			{
				Transition* tmp = list.first;
				if(tmp.ReturnValue())
				{
					SetCurrentState(list.second);
				}
			}
		}
};

class Job
{
	private:
		std::string label;
		StateMachine* state_machine;
	public:
		Job() : label("woodworker") { }
		Job(std::string name) : label(name) { }

		void CreateStateMachine()
		{
			States* idle = new States(ST_IDLE);
			States* moving = new States(ST_MOVING);
			Transition* transition = new Transition(); //"gamestate", "condition"
			idle->AddTransition(transition, moving);
			if (state_machine->GetCurrentState->GetTransitionList.size() == 0) state_machine = new StateMachine(idle);
		}
		void Destroy(){	delete state_machine; }

};

class People
{
	private:
		Position pos{0.f,0.f};
		int quantityInPocket;
		Job job;
	public:
		People() { job = Job();  quantityInPocket = 0;}
		People(Job work, int pocket) : job(work), quantityInPocket(pocket) { }
		Position GetPosition() { return pos; }
		int GetQuantityInPocket() { return quantityInPocket; }
};
// créer classe stateMachine , transition, people
// enum job ----> enum action pour chaque job --> différentes actions possibles

int main()
{	
	try 
	{
		
	} 
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
