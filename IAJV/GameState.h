#pragma once
struct Position {
	float x, y;
	bool operator==(const Position& p) { return (x == p.x && y == p.y); }
};

struct GameState
{
	int Stock, raffinedStock, numberOfHouses, maxQtInPocket, qtToBuild = 1000;
	Position beginPos, forestPos, stockPos, buildPos;
};