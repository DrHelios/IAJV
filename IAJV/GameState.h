#pragma once
#include "Position.h"
struct GameState
{
	int Stock, raffinedStock, numberOfHouses, maxQtInPocket, qtToBuild = 1000;
	Position beginPos, forestPos, stockPos, buildPos;
};