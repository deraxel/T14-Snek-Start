#pragma once
#include "snek.h"
#include "board.h"
#include <random>

class Goal{
private:
	Location loc;
	static constexpr Color c=Colors::Red;
public:
	Goal(std::mt19937&,const Board&,const Snek&);
	void respawn(std::mt19937&,const Board&,const Snek&);
	const Location& getLoc() const;
	void draw(Board&) const;
};