#pragma once
#include "Transition.h"
class IdleToFinish : public Transition
{
public:
	IdleToFinish();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~IdleToFinish();
};

class IdleToMoving : public Transition
{
public:
	IdleToMoving();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~IdleToMoving();
};

class MovingToGather : public Transition
{
public:
	MovingToGather();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~MovingToGather();
};

class GatherToMoving : public Transition
{
public:
	GatherToMoving();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~GatherToMoving();
};

class MovingToFlee : public Transition
{
public:
	MovingToFlee();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~MovingToFlee();
};

class FleeToDeath : public Transition
{
public:
	FleeToDeath();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~FleeToDeath();
};

class FleeToGather : public Transition
{
public:
	FleeToGather();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~FleeToGather();
};

class FleeToStock : public Transition
{
public:
	FleeToStock();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~FleeToStock();
};

class FleeToMoving : public Transition
{
public:
	FleeToMoving();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~FleeToMoving();
};

class MovingToStock : public Transition
{
public:
	MovingToStock();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~MovingToStock();
};

class StockToIdle : public Transition
{
public:
	StockToIdle();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~StockToIdle();
};

class IdleToCraftIdle : public Transition
{
public:
	IdleToCraftIdle();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~IdleToCraftIdle();
};

class CraftIdleToMove : public Transition
{
public:
	CraftIdleToMove();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~CraftIdleToMove();
};

class MoveToReffine : public Transition
{
public:
	MoveToReffine();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~MoveToReffine();
};

class ReffineToMove : public Transition
{
public:
	ReffineToMove();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~ReffineToMove();
};

class MoveToStock : public Transition
{
public:
	MoveToStock();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~MoveToStock();
};

class StockToCraftIdle : public Transition
{
public:
	StockToCraftIdle();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~StockToCraftIdle();
};

class CraftIdleToBuild : public Transition
{
public:
	CraftIdleToBuild();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~CraftIdleToBuild();
};

class BuildToDone : public Transition
{
public:
	BuildToDone();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~BuildToDone();
};

class DoneToIdle : public Transition
{
public:
	DoneToIdle();
	virtual bool ReturnValue(const People& p, const GameState& gm) const;
	virtual ~DoneToIdle();
};
