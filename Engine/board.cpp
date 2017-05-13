#include "board.h"
#include "location.h"
#include "SpriteCodex.h"
#include <assert.h>

Board::Board(Graphics& gfx):
	gfx(gfx){
	bX=((gfx.ScreenWidth/2)-(dimension*width/2));
	bY=((gfx.ScreenHeight/2)-(dimension*height/2));
	drawBoarder();
}

void Board::drawCell(const Location& loc, Color c) {
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	const int offX=bX;
	const int offY=bY;
	gfx.DrawRectDim(offX+loc.x*dimension, loc.y*dimension,offY+dimension,dimension,c);
}

void Board::drawSnek(const Location& loc,const int spriteSeg,const int dir){
	if(spriteSeg==0){
		drawSnekHead(loc,dir);
	} else if(spriteSeg==1){
		drawSnekBodyEven(loc,dir);
	} else if(spriteSeg==2){
		drawSnekBodyOdd(loc,dir);
	} else{
		drawSnekTail(loc,dir);
	}
}

void Board::drawSnekHead(const Location& loc,const int dir){
	if(dir==0){
		SpriteCodex::drawHeadRight(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==1){
		SpriteCodex::drawHeadDown(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==2){
		SpriteCodex::drawHeadLeft(loc.x*dimension,loc.y*dimension,gfx);
	} else{
		SpriteCodex::drawHeadUp(loc.x*dimension,loc.y*dimension,gfx);
	}
}

void Board::drawSnekBodyOdd(const Location& loc,const int dir){
	if(dir==0){
		SpriteCodex::drawBodyRight(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==1){
		SpriteCodex::drawBodyDown(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==2){
		SpriteCodex::drawBodyLeft(loc.x*dimension,loc.y*dimension,gfx);
	} else{
		SpriteCodex::drawBodyUp(loc.x*dimension,loc.y*dimension,gfx);
	}
}

void Board::drawSnekBodyEven(const Location& loc,const int dir){
	if(dir==0){
		SpriteCodex::drawBodyLeft(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==1){
		SpriteCodex::drawBodyUp(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==2){
		SpriteCodex::drawBodyRight(loc.x*dimension,loc.y*dimension,gfx);
	} else{
		SpriteCodex::drawBodyDown(loc.x*dimension,loc.y*dimension,gfx);
	}
}

void Board::drawSnekTail(const Location& loc,const int dir){
	if(dir==0){
		SpriteCodex::drawTailRight(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==1){
		SpriteCodex::drawTailDown(loc.x*dimension,loc.y*dimension,gfx);
	} else if(dir==2){
		SpriteCodex::drawTailLeft(loc.x*dimension,loc.y*dimension,gfx);
	} else{
		SpriteCodex::drawTailUp(loc.x*dimension,loc.y*dimension,gfx);
	}
}

int Board::getH()const {
	return height;
}

int Board::getW()const {
	return width;
}

bool Board::isInsideBoard(const Location& loc)const {
	return loc.x >= bX/dimension && loc.x<width+bX/dimension && loc.y < height+bY/dimension && loc.y>=bY/dimension;
}

void Board::drawGoal(const Location& loc){
	SpriteCodex::drawGoal((loc.x)*dimension,(+loc.y)*dimension,gfx);
}

void Board::drawBlock(const Location& loc){
	SpriteCodex::drawBlock((loc.x)*dimension,(loc.y)*dimension,gfx);
}

void Board::drawBoarder(){
	const int top=bY-borderPadding;
	const int left=bX-borderPadding;
	const int bottom=bY+(height*dimension)+borderPadding;
	const int right=bX+(width*dimension)+borderPadding;

	gfx.DrawRect(left-boarderWidth,top-boarderWidth,right+boarderWidth,bottom+boarderWidth,borderColor);
	gfx.DrawRect(left,top,right,bottom,fieldColor);
}

int Board::getBxStart() const{
	return bX/dimension;
}

int Board::getByStart() const{
	return bY/dimension;
}