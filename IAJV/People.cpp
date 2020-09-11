#include "People.h"
#include "Transition.h"

People::People() : quantityInPocket(0), name("Maurice") { }
People::People(int pocket) : quantityInPocket(pocket), name("Maurice") { }
People::People(std::string param_name) : quantityInPocket(0), name(param_name) { }
std::string People::GetName() const { return name; }
Position People::GetPosition() const { return pos; }
int People::GetQuantityInPocket() const { return quantityInPocket; }
StateMachine* People::GetStateMachine() { return state_machine; }
void People::CreateStateMachine(States* state) { state_machine = new StateMachine(state); }
void People::DestroyStateMachine() { delete state_machine; }
int People::SetChanceToFlee() const
{
	int test = rand() % 100;
	return (test);
}
Position People::CalculateStep(Position beginPos, Position destinationPos) const
{
	float stepX = abs(beginPos.x - destinationPos.x);
	float stepY = abs(beginPos.y - destinationPos.y);
	float maxValue = std::fmaxf(stepX, stepY);
	if (stepX != 0 && stepY != 0)
	{
		stepX = stepX / maxValue;
		stepY = stepY / maxValue;
		stepX = std::copysignf(stepX, destinationPos.x - beginPos.x);
		stepY = std::copysignf(stepY, destinationPos.y - beginPos.y);
	}
	return { stepX, stepY };
}

void People::ProcessState(GameState& gs)
{
	States* currentState = this->state_machine->GetCurrentState();
	Transition* tmp = NULL;
	for (std::pair<Transition*, int>& list : currentState->GetTransitionList())
	{
		tmp = list.first;
		if (tmp->ReturnValue(*this, gs) && currentState->GetPossibleState() != list.second && list.first->getPreviousState() == currentState->GetPossibleState())
		{
			this->state_machine->SetCurrentState(list.second);
			break;
		}
	}
	switch (currentState->GetPossibleState())
	{
	case possibleStates::ST_FINISH:
		std::cout << "We did it chief ! Our new life is beggining !" << std::endl;
		break;
	case possibleStates::ST_IDLE:
		std::cout << "Chillin with the boys" << std::endl;
		break;
	case possibleStates::ST_MOVING:
	{
		std::cout << "On my way Chief !" << std::endl;
		switch (tmp->getPreviousState())
		{
		case possibleStates::ST_IDLE:
			gs.steping = this->CalculateStep(this->pos, gs.forestPos);
			break;
		case possibleStates::ST_GATHER:
			gs.steping = this->CalculateStep(gs.forestPos, gs.stockPos);
			break;
		}
		this->pos.x += gs.steping.x;
		this->pos.y += gs.steping.y;
		std::cout << "My new pos is : X : " << this->pos.x << " Y : " << this->pos.y << std::endl;
		break;
	}
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
		std::cout << "A WOLF ! NINGERU DA YOOOOOOOOOOOOOOO" << std::endl;
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
		std::cout << "Pockets are full ! Let's move" << std::endl;
		break;
	case craftHouseState::ST_MOVE:
	{
		std::cout << "On my way Chief !" << std::endl;
		switch (tmp->getPreviousState())
		{
		case craftHouseState::ST_CRAFTIDLE:
			gs.steping = this->CalculateStep(this->pos, gs.stockPos);
			break;
		case craftHouseState::ST_REFFINE:
			gs.steping = this->CalculateStep(this->pos, gs.buildPos);
			break;
		}
		this->pos.x += gs.steping.x;
		this->pos.y += gs.steping.y;
		std::cout << "My new pos is : X : " << this->pos.x << " Y : " << this->pos.y << std::endl;
		break;
	}
	case craftHouseState::ST_STOCKREF:
		std::cout << "*Noises of wood being cut* " << std::endl;
		gs.raffinedStock += this->quantityInPocket;
		this->quantityInPocket = 0;
		std::cout << "We have " << gs.raffinedStock << " plates in the raffinedStock." << std::endl;
		break;
	case craftHouseState::ST_BUILD:
		std::cout << "Building that sweeeeeeeeet home" << std::endl;
		gs.raffinedStock -= gs.qtToBuild;
		gs.curNbOfHouse += 1;
		break;
	case craftHouseState::ST_DONE:
		std::cout << "Done chief ! Looks pretty cool !" << std::endl;
		std::cout << "We have now " << gs.curNbOfHouse << " houses, only " << gs.numberOfHouses - gs.curNbOfHouse << " more !" << std::endl;
		break;
	}
}





