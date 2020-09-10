#pragma once
#include "Transition.h"
class IdleToMove : public Transition
{
public:
	virtual bool ReturnValue(const People& p , const GameState& gm) const { return (gm.Stock != gm.qtToBuild); }
	virtual ~IdleToMove() {}
};

class MoveToGather : public Transition
{
public:
	virtual bool ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.forestPos); }
	virtual ~MoveToGather() {}
};

class GatherToMove : public Transition
{
public:
	virtual bool ReturnValue(const People& p, const GameState& gm) const { return (p.GetQuantityInPocket() == gm.maxQtInPocket); }
	virtual ~GatherToMove() {}
};

class MoveToStock : public Transition
{
public:
	virtual bool ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.stockPos); }
	virtual ~MoveToStock() {}
};

class StockToIdle : public Transition
{
public:
	virtual bool ReturnValue(const People& p, const GameState& gm) const { return (p.GetPosition() == gm.beginPos); }
	virtual ~StockToIdle() {}
};

class IdleToCrafthouse : public Transition
{
public:
	virtual bool ReturnValue(const People& p, const GameState& gm) const { return (gm.Stock == gm.qtToBuild); }
	virtual ~IdleToCrafthouse() {}
};