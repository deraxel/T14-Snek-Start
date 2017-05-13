#pragma once
#include "snek.h"
#include "board.h"
#include <random>
#include "goal.h"

class Block{
	bool notInfront(Location,Location);
	bool notOnGoal(Location,Goal);
private:
	Location loc;
	int sepera;
public:
	Block();
	Block(const Board&);
	Block(std::mt19937&,const Board&,const Snek&,const Goal&);
	void spawn(std::mt19937&,const Board&,Snek,Goal);
	const Location& getLoc() const;
	void draw(Board&) const;
};