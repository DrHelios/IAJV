// IAJV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "People.h"
#include "WorkerTransitions.h"
#include "Helper.h"


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

GameState game_state;
std::vector<People> peopleList;
std::string name;
float x, y;
int nb_personne;

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
		nb_personne = 1;
		x = 1;
		y = 1;
		game_state.beginPos = { 0, 0 };
		game_state.Stock = 0;
		game_state.raffinedStock = 0;

		std::cout << "choix quantité max dans pocket" << std::endl;
		std::cin >> game_state.maxQtInPocket;

		std::cout << "choix quantité max dans de maison à construire" << std::endl;
		std::cin >> game_state.numberOfHouses;

		std::cout << "choix de la position x de la foret" << std::endl;
		std::cin >> x;
		std::cout << "choix de la position y de la foret" << std::endl;
		std::cin >> y;
		game_state.forestPos = { x, y };

		std::cout << "choix de la position x de la zone de construction" << std::endl;
		std::cin >> x;
		std::cout << "choix de la position y de la zone de construction" << std::endl;
		std::cin >> y;
		game_state.buildPos = { x, y };

		std::cout << "choix de la position x du stockage" << std::endl;
		std::cin >> x;
		std::cout << "choix de la position y du stockage" << std::endl;
		std::cin >> y;
		game_state.stockPos = { x, y };

		std::cout << "choix du nombre de personne" << std::endl;
		std::cin >> nb_personne;

		for (int i = 0; i < nb_personne;++i)
		{
			std::cout << "choix du nom de la personne" << std::endl;
			std::cin >> name;
			People p = People(name);
			peopleList.push_back(p);
		}




	} 
	catch (std::exception e)
	{
		std::cout << "Erreur lors du traitement du main : " << e.what() << std::endl;
	}
	return 0;
}
