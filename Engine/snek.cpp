#include "snek.h"
#include <assert.h>
#include "location.h"
#include "SpriteCodex.h"

Snek::Snek(const Location & loc){
	segments[0].initHead(loc);
}

void Snek::moveBy(const Location& delta_loc) {
	for (int i = nSegs - 1; i > 0; i--) {
		segments[i].follow(segments[i - 1]);
	}
	segments[0].moveBy(delta_loc);
}

void Snek::grow() {
	if (nSegs < maxSeg) {
		segments[nSegs].initBody(nSegs);
		nSegs++;
	}
}

bool Snek::isInTile(const Location& tar,int check)const{//check 0 or 1 depending on including the tail or not.  0 for not 1 to include
	for (int i = 0; i < nSegs-1+check; i++) {
		if (segments[i].getLoca() == tar) {
			return true;
		}
	}
	return false;
}

void Snek::draw(Board& brd) const {
	for (int i = 0; i < nSegs-1; i++) {
		segments[i].draw(brd,false,nSegs);
	}
	segments[nSegs-1].draw(brd,true,nSegs);
}

Location Snek::getNextHead(const Location & delta_loc) const
{
	Location l(segments[0].getLoca());
	l.add(delta_loc);
	return l;
}

void Snek::Segment::follow(const Segment & next){
	loc = next.loc;
	dir = next.dir;
}

void Snek::Segment::initHead(const Location& locT) {
	loc = locT;
	c = Snek::headColor;
	spriteGen=0;
}

 Location Snek::getHead(){
	return segments[0].getHead();
}

void Snek::Segment::initBody(int segs) {
	c = Snek::bodyColor;
	if(segs%2==0){
		spriteGen=1;
	}else{
		spriteGen=2;
	}
}

void Snek::Segment::draw(Board& brd,bool isLast,int const segs)const {
	//brd.drawCell(loc, c);
	if(segs==1){
		brd.drawSnekHead(loc,dir);
	} else{
		if(!isLast){
			brd.drawSnek(loc,spriteGen,dir);
		} else{
			brd.drawSnek(loc,3,dir);
		}
	}
}

void Snek::Segment::moveBy(const Location& delta_loc) {
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
	Location loc2{1,0};
	if(delta_loc==loc2){
		dir=0;
	}
	loc2.x=0;
	loc2.y=1;
	if(delta_loc==loc2){
		dir=1;
	}
	loc2.x=-1;
	loc2.y=0;
	if(delta_loc==loc2){
		dir=2;
	}
	loc2.x=0;
	loc2.y=-1;
	if(delta_loc==loc2){
		dir=3;
	}
}

Location Snek::Segment::getLoca() const {
	return loc;
}

Location Snek::Segment::getHead(){
	return loc;
}
