#include "People.h"
#include "Transition.h"

void People::ProcessState(const GameState& gs)
{
	for (const std::pair<const Transition*, States*>& list : state_machine->GetCurrentState()->GetTransitionList())
	{
		const  Transition* tmp = list.first;
		if (tmp->ReturnValue(*this, gs))
		{
			state_machine->SetCurrentState(list.second);
			break;
		}
	}
	state_machine->GetCurrentState()->Process();
}