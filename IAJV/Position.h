#pragma once
struct Position {
	float x, y;
	bool operator==(const Position& p) { return (x == p.x && y == p.y); }
};
