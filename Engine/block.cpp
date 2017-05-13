#include "block.h"
#include "board.h"
#include <random>
#include "goal.h"

Block::Block(){
}

Block::Block(const Board& brd){
	sepera=brd.getW()/8;
}

bool Block::notInfront(Location loca,Location snek){
	return !(!(abs(loca.x-snek.x)>sepera)&&!(abs(loca.y-snek.y)>sepera));
}

bool Block::notOnGoal(Location loca,Goal goal){
	return !(goal.getLoc().x==loca.x && goal.getLoc().y==loca.y);
}

Block::Block(std::mt19937& rng,const Board& brd,const Snek& snek,const Goal& goal){
	spawn(rng,brd,snek,goal);
}

void Block::spawn(std::mt19937& rng,const Board& brd,Snek snek,Goal goal){
	std::uniform_int_distribution<int> xDist(brd.getBxStart(),brd.getW()-1+brd.getByStart());
	std::uniform_int_distribution<int> yDist(brd.getByStart(),brd.getH()-1+brd.getByStart());
	goal.getLoc().x;
	Location newLoc;
	do{
  		newLoc.x=xDist(rng);
		newLoc.y=yDist(rng);;
	} while(!(Block::notInfront(newLoc,snek.getHead())&&!snek.isInTile(newLoc,1)&&notOnGoal(newLoc,goal)));

	loc=newLoc;
}

void Block::draw(Board& brd) const{
	brd.drawBlock(loc);
}

const Location& Block::getLoc() const{
	return loc;
}

