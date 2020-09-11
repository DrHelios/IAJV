
#include <iostream>
#include <vector>
#include <string>

struct Position {
	float x, y;
	bool operator==(Position& p) { return (x == p.x && y == p.y); }
};

struct GameState
{
	int Stock, raffinedStock, curNbOfHouse, numberOfHouses, maxQtInPocket = 200, qtToBuild = 1000;
	Position beginPos, forestPos, stockPos, buildPos;
};

class Transition;

enum possibleStates { ST_IDLE, ST_MOVING, ST_GATHER, ST_FILLING, ST_FLEE, ST_DEATH, ST_FINISH };
enum craftHouseState { ST_CRAFTIDLE = 10, ST_REFFINE = 11, ST_STOCKREF = 12, ST_BUILD = 13, ST_DONE = 14 };

class States
{
private:
	std::vector<std::pair<Transition*, int>> transistionList;
public:
	int actualState;
	States() : transistionList() {}
	States(possibleStates state) : actualState(state), transistionList() {}
	~States()
	{
		transistionList.clear();
	}
	std::vector<std::pair<Transition*, int>> GetTransitionList(){ return transistionList; }

	int GetPossibleState() { return actualState; }
	// Ajoute une transition à la liste des transition
	void AddTransition(Transition* transitionToUpdateStates, int targetStates) { transistionList.push_back(std::make_pair(transitionToUpdateStates, targetStates)); }
};

class Process;

class StateMachine
{
private:
	States* begin;
	States* current_states;
public:
	StateMachine() : begin(), current_states() {}
	StateMachine(States* start) : begin(start), current_states(start) { }
	~StateMachine() { delete begin; }

	States* GetBeginState(){ return begin; };

	States* GetCurrentState(){ return current_states; };

	void SetCurrentState(int newCurrentState) { current_states->actualState = newCurrentState; }

};

class People;

class Transition
{
public:
	int previousState;
	Transition(int pvState) : previousState(pvState){}
	virtual bool ReturnValue(People p, GameState gm) = 0;

};

class People
{
private:
	Position pos{ 0.f,0.f };
	int quantityInPocket;
	StateMachine* state_machine;
public:
	People() { quantityInPocket = 0; }
	People(int pocket) : quantityInPocket(pocket) { }
	Position GetPosition() { return pos; }
	int GetQuantityInPocket() { return quantityInPocket; }
	StateMachine* GetStateMachine() { return state_machine; }
	void CreateStateMachine(States* state) { state_machine = new StateMachine(state); }
	void DestroyStateMachine() { delete state_machine; }

	void ProcessState(GameState& gs)
	{
		States* currentState = this->state_machine->GetCurrentState();
		for (std::pair<Transition*, int>& list : currentState->GetTransitionList())
		{
			Transition* tmp = list.first;
			if (tmp->ReturnValue(*this, gs) && currentState->actualState != list.second && list.first->previousState == currentState->actualState)
			{
				this->state_machine->SetCurrentState(list.second);
				break;
			}
		}
		switch (currentState->actualState)
		{
			case possibleStates::ST_FINISH:
				std::cout << "We did it chief ! Our new life is beggining !" << std::endl;
				break;
			case possibleStates::ST_IDLE:
				std::cout << "Chillin with the boys" << std::endl;
					break;
			case possibleStates::ST_MOVING:
				std::cout << "On my way Chief !" << std::endl;
				break;
			case possibleStates::ST_GATHER:
				std::cout << "Gathering all the loot I can" << std::endl;
				this->quantityInPocket = gs.maxQtInPocket;
				std::cout << "My pocket are full, let's back home !" << std::endl;
				break;
			case possibleStates::ST_FILLING:
				std::cout << "Putting the LOOTA in the chest" << std::endl;
				gs.Stock += this->quantityInPocket;
				this->quantityInPocket = 0;
				std::cout << "We have " << gs.Stock << " Woods in the stock." << std::endl;
				break;
			case possibleStates::ST_FLEE:
				std::cout << "NINGERU DA YOOOOOOOOOOOOOOO" << std::endl;
				break;
			case possibleStates::ST_DEATH:
				std::cout << "I don't feel so good, mister chief ....." << std::endl;
				break;
			case craftHouseState::ST_CRAFTIDLE:
				std::cout << "Now we have enought wood to build, let's do this !" << std::endl;
				break;
			case craftHouseState::ST_REFFINE:
				std::cout << "Let's use this wood to make plate !" << std::endl;
				gs.Stock -= gs.maxQtInPocket;
				this->quantityInPocket = gs.maxQtInPocket;
				break;
			case craftHouseState::ST_STOCKREF:
				std::cout << "*Noises of wood being cut* " << std::endl;
				gs.raffinedStock += this->quantityInPocket;
				this->quantityInPocket = 0;
				std::cout << "We have " << gs.raffinedStock << " plates in the raffinedStock." << std::endl;
				break;
			case craftHouseState::ST_BUILD:
				std::cout << "Building that sweeeeeeeeet home" << std::endl;
				gs.raffinedStock = 0;
				gs.curNbOfHouse += 1;
				break;
			case craftHouseState::ST_DONE:
				std::cout << "Done chief ! Looks pretty cool !" << std::endl;
				std::cout << "We have now " << gs.curNbOfHouse << " houses, only " << gs.numberOfHouses - gs.curNbOfHouse << " more !" << std::endl;
				break;
		}
	}
};

#pragma region Transitions
class IdleToFinish : public Transition
{
public:
	IdleToFinish() : Transition(possibleStates::ST_IDLE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (gm.curNbOfHouse == gm.numberOfHouses); }
	virtual ~IdleToFinish() {}
};

class IdleToMove : public Transition
{
public:
	IdleToMove() : Transition(possibleStates::ST_IDLE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (gm.Stock != gm.qtToBuild); }
	virtual ~IdleToMove() {}
};

class MoveToGather : public Transition
{
public:
	MoveToGather() : Transition(possibleStates::ST_MOVING) {}
	virtual bool ReturnValue(People p, GameState gm) { return (p.GetPosition() == gm.forestPos && p.GetQuantityInPocket() == 0); }
	virtual ~MoveToGather() {}
};

class GatherToMove : public Transition
{
public:
	GatherToMove() : Transition(possibleStates::ST_GATHER) {}
	virtual bool ReturnValue(People p, GameState gm) { return (p.GetQuantityInPocket() == gm.maxQtInPocket); }
	virtual ~GatherToMove() {}
};

class MoveToStock : public Transition
{
public:
	MoveToStock() : Transition(possibleStates::ST_MOVING) {}
	virtual bool ReturnValue(People p, GameState gm) { return (p.GetPosition() == gm.stockPos); }
	virtual ~MoveToStock() {}
};

class StockToIdle : public Transition
{
public:
	StockToIdle() : Transition(possibleStates::ST_FILLING) {}
	virtual bool ReturnValue(People p, GameState gm) { return (p.GetPosition() == gm.beginPos); }
	virtual ~StockToIdle() {}
};

class IdleToCraftIdle : public Transition
{
public:
	IdleToCraftIdle() : Transition(possibleStates::ST_IDLE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (gm.Stock == gm.qtToBuild); }
	virtual ~IdleToCraftIdle() {}
};

class CraftIdleToReffine : public Transition
{
public:
	CraftIdleToReffine() : Transition(craftHouseState::ST_CRAFTIDLE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (gm.raffinedStock < gm.qtToBuild); }
	virtual ~CraftIdleToReffine() {}
};

class ReffineToStock : public Transition
{
public:
	ReffineToStock() : Transition(craftHouseState::ST_REFFINE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (true); }
	virtual ~ReffineToStock() {}
};

class StockToCraftIdle: public Transition
{
public:
	StockToCraftIdle() : Transition(craftHouseState::ST_STOCKREF) {}
	virtual bool ReturnValue(People p, GameState gm) { return (true); }
	virtual ~StockToCraftIdle() {}
};

class CraftIdleToBuild : public Transition
{
public:
	CraftIdleToBuild() : Transition(craftHouseState::ST_CRAFTIDLE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (gm.raffinedStock == gm.qtToBuild); }
	virtual ~CraftIdleToBuild() {}
};

class BuildToDone : public Transition
{
public:
	BuildToDone() : Transition(craftHouseState::ST_BUILD) {}
	virtual bool ReturnValue(People p, GameState gm) { return (true); }
	virtual ~BuildToDone() {}
};

class DoneToIdle : public Transition
{
public:
	DoneToIdle() : Transition(craftHouseState::ST_DONE) {}
	virtual bool ReturnValue(People p, GameState gm) { return (true); }
	virtual ~DoneToIdle() {}
};


#pragma endregion

GameState gs;
float x, y;

int main()
{
		x = 1;
		y = 1;
		gs.beginPos = { 0, 0 };
		gs.Stock = 0;
		gs.raffinedStock = 0;

	int test;
	possibleStates pSt = possibleStates::ST_IDLE;
	States* s = new States(pSt);
	s->AddTransition(new IdleToFinish(), possibleStates::ST_FINISH);
	s->AddTransition(new IdleToMove(), possibleStates::ST_MOVING);
	s->AddTransition(new MoveToGather(), possibleStates::ST_GATHER);
	s->AddTransition(new GatherToMove(), possibleStates::ST_MOVING);
	s->AddTransition(new MoveToStock(), possibleStates::ST_FILLING);
	s->AddTransition(new StockToIdle(), possibleStates::ST_IDLE);
	s->AddTransition(new IdleToCraftIdle(), craftHouseState::ST_CRAFTIDLE);
	s->AddTransition(new CraftIdleToReffine(), craftHouseState::ST_REFFINE);
	s->AddTransition(new ReffineToStock(), craftHouseState::ST_STOCKREF);
	s->AddTransition(new StockToCraftIdle(), craftHouseState::ST_CRAFTIDLE);
	s->AddTransition(new CraftIdleToBuild(), craftHouseState::ST_BUILD);
	s->AddTransition(new BuildToDone(), craftHouseState::ST_DONE);
	s->AddTransition(new DoneToIdle(), possibleStates::ST_IDLE);

#pragma region Paramétrage
	std::cout << "choix quantite max dans pocket" << std::endl;
	std::cin >> gs.maxQtInPocket;

	std::cout << "choix quantite max dans de maison a construire" << std::endl;
	std::cin >> gs.numberOfHouses;

	std::cout << "choix de la position x de la foret" << std::endl;
	std::cin >> x;
	std::cout << "choix de la position y de la foret" << std::endl;
	std::cin >> y;
	gs.forestPos = { x, y };

	std::cout << "choix de la position x de la zone de construction" << std::endl;
	std::cin >> x;
	std::cout << "choix de la position y de la zone de construction" << std::endl;
	std::cin >> y;
	gs.buildPos = { x, y };

	std::cout << "choix de la position x du stockage" << std::endl;
	std::cin >> x;
	std::cout << "choix de la position y du stockage" << std::endl;
	std::cin >> y;
	gs.stockPos = { x, y };
#pragma endregion

	People p = People();
	p.CreateStateMachine(s);
	while (p.GetStateMachine()->GetCurrentState()->actualState != possibleStates::ST_FINISH)
	{
		p.ProcessState(gs);
		while (std::cin.get() != '\n') {}
	}
	p.DestroyStateMachine();
	return 0;
}