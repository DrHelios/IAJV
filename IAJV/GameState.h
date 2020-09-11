#pragma once
#include "Position.h"
struct GameState
{
	int Stock, raffinedStock, curNbOfHouse, numberOfHouses, maxQtInPocket = 200, qtToBuild = 1000;
	Position beginPos, forestPos, stockPos, buildPos, steping;
};