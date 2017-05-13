#include "goal.h"
#include "board.h"
#include <random>


Goal::Goal(std::mt19937& rng,const Board& brd,const Snek& snek){
	respawn(rng,brd,snek);
}

void Goal::respawn(std::mt19937& rng,const Board& brd, const Snek& snek){
	std::uniform_int_distribution<int> xDist(brd.getBxStart(),brd.getW()-1+brd.getByStart());
	std::uniform_int_distribution<int> yDist(brd.getByStart(),brd.getH()-1+brd.getByStart());

	Location newLoc;
	do{
		newLoc.x=xDist(rng);
		newLoc.y=yDist(rng);
	} while(snek.isInTile(newLoc,1));

	loc=newLoc;
}

void Goal::draw(Board& brd) const{
	//brd.drawCell(loc,c);
	brd.drawGoal(loc);
}

const Location& Goal::getLoc() const{
	return loc;
}

