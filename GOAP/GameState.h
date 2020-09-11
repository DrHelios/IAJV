#pragma once
#include "People.h"
#include<vector>

struct GameState
{
	int Stock, raffinedStock, curNbOfHouse, numberOfHouses, maxQtInPocket, nbWorkerMax = 5, nbTree = 10000, maxWood = 100, qtToBuild = 1000;
	std::vector<People> villagers;
	//Position beginPos, forestPos, stockPos, buildPos;
};

/*static int totalWood;
static int maxWood = 1000;
static int qtToBuild;
static int woodworkerNb;
static int housesNb;*/