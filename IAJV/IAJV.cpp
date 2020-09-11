//// IAJV.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include "People.h"
//#include "WorkerTransitions.h"
//#include "WorkerStates.h"
//#include "Helper.h"
//#include <cassert>
//
//
//// créer classe stateMachine , transition, people
//// enum job ----> enum action pour chaque job --> différentes actions possibles
//void CreateStateMachineForPeople(People &p)
//{
//	States* idle = new IdleState(ST_IDLE);
//	p.CreateStateMachine(idle);
//	States* moving = new MoveState(ST_MOVING);
//	States* gather = new GatherState(ST_GATHER);
//	States* stock = new StockState(ST_FILLING);
//	States* craft = new CraftState(ST_CRAFT);
//	States* death = new DeathState(ST_DEATH);
//	Transition* idle_to_move = new IdleToMove(); 
//	Transition* move_to_gather = new MoveToGather();
//	Transition* gather_to_move = new GatherToMove();
//	Transition* move_to_stock = new MoveToStock();
//	Transition* stock_to_idle = new StockToIdle();
//	Transition* idle_to_craft = new IdleToCrafthouse();
//	idle->AddTransition(idle_to_move, moving);
//	moving->AddTransition(move_to_gather, gather);
//	gather->AddTransition(gather_to_move, moving);
//	moving->AddTransition(move_to_stock, stock);
//	stock->AddTransition(stock_to_idle, idle);
//	idle->AddTransition(idle_to_craft, craft);
//	StateMachine* st = p.GetStateMachine();
//	assert((st != nullptr));
//	if (st != nullptr)
//	{
//		States* current = st->GetCurrentState();
//		assert(current != nullptr);
//		if (current != nullptr)
//		{
//			std::vector<std::pair<Transition*, States*>> transList = current->GetTransitionList();
//			if (transList.size() == 0) p.CreateStateMachine(idle);
//		}
//	}
//}
//void DestroyStateMachineForPeople(People &p) { p.DestroyStateMachine(); }
//
//GameState game_state;
//std::vector<People> peopleList;
//std::string name;
//float x, y;
//int nb_personne;
//
//int main()
//{	
//	try 
//	{
//		nb_personne = 1;
//		x = 1;
//		y = 1;
//		game_state.beginPos = { 0, 0 };
//		game_state.Stock = 0;
//		game_state.raffinedStock = 0;
//
//		std::cout << "choix quantite max dans pocket" << std::endl;
//		std::cin >> game_state.maxQtInPocket;
//
//		std::cout << "choix quantite max dans de maison a construire" << std::endl;
//		std::cin >> game_state.numberOfHouses;
//
//		std::cout << "choix de la position x de la foret" << std::endl;
//		std::cin >> x;
//		std::cout << "choix de la position y de la foret" << std::endl;
//		std::cin >> y;
//		game_state.forestPos = { x, y };
//
//		std::cout << "choix de la position x de la zone de construction" << std::endl;
//		std::cin >> x;
//		std::cout << "choix de la position y de la zone de construction" << std::endl;
//		std::cin >> y;
//		game_state.buildPos = { x, y };
//
//		std::cout << "choix de la position x du stockage" << std::endl;
//		std::cin >> x;
//		std::cout << "choix de la position y du stockage" << std::endl;
//		std::cin >> y;
//		game_state.stockPos = { x, y };
//
//		std::cout << "choix du nombre de personne" << std::endl;
//		std::cin >> nb_personne;
//
//		for (int i = 0; i < nb_personne;++i)
//		{
//			std::cout << "choix du nom de la personne" << std::endl;
//			std::cin >> name;
//			People p = People(name);
//			peopleList.push_back(p);
//		}
//		CreateStateMachineForPeople(peopleList[0]);
//		peopleList[0].ProcessState(game_state);
//
//
//		DestroyStateMachineForPeople(peopleList[0]);
//
//	} 
//	catch (std::exception e)
//	{
//		std::cout << "Erreur lors du traitement du main : " << e.what() << std::endl;
//	}
//	return 0;
//}
