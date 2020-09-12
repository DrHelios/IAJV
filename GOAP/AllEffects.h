#pragma once
#include "Effect.h"

class ChopWood : public Effect
{
public:
	ChopWood();
	ChopWood(Condition cond);
	virtual void Process(People& p, GameState& gs)const;
	~ChopWood();

}; 

class ReffineWood : public Effect
{
public:
	ReffineWood();
	ReffineWood(Condition cond);
	virtual void Process(People& p, GameState& gs) const;
	~ReffineWood();

};

class BuildHouse: public Effect
{
public:
	BuildHouse();
	BuildHouse(Condition cond);
	virtual void Process(People& p, GameState& gs) const;
	~BuildHouse();

};

class Stock : public Effect
{
public:
	Stock();
	Stock(Condition cond);
	virtual void Process(People& p, GameState& gs) const;
	~Stock();
};

class LiberateVillager : public Effect
{
public:
	LiberateVillager();
	LiberateVillager(Condition cond);
	virtual void Process(People& p, GameState& gs) const;
	~LiberateVillager();
};

class AssignVillager : public Effect
{
public:
	AssignVillager();
	AssignVillager(Condition cond);
	virtual void Process(People& p, GameState& gs) const;
	~AssignVillager();
};