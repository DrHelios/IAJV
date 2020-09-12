#pragma once
#include "People.h"
#include<vector>

struct GameState
{
	int Stock, raffinedStock, curNbOfHouse, numberOfHouses, maxQtInPocket, nbWorkerMax,
		nbTree = 10000, qtToBuild = 1000;
	std::vector<People> villagers;
};