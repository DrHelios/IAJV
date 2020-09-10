// IAJV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "People.h"
#include "WorkerTransitions.h"


// créer classe stateMachine , transition, people
// enum job ----> enum action pour chaque job --> différentes actions possibles
void CreateStateMachineForPeople(People &p)
{
	States* idle = new States(ST_IDLE);
	States* moving = new States(ST_MOVING);
	Transition* transition = new IdleToMove(); //"gamestate", "condition"
	idle->AddTransition(transition, moving);
	if (p.GetStateMachine()->GetCurrentState()->GetTransitionList().size() == 0) p.CreateStateMachine(idle);
}
void DestroyStateMachineForPeople(People &p) { p.DestroyStateMachine(); }

int main()
{	
	try 
	{
		//int nbOfWorkers;
		//std::cout << "Enter the number of workers : " << std::endl;
		//cin >> nbOfWorkers;
		//for (int i = 0; i < nbOfWorkers)
		//{
		//}
		People p = People();


	} 
	catch (std::exception e)
	{
		std::cout << "Erreur lors du traitement du main : " << e.what() << std::endl;
	}
	return 0;
}
