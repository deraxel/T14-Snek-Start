#include "MainWindow.h"
#include "Game.h"
#include "snek.h"
#include "SpriteCodex.h"
#include "block.h"
#include "framerate.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek({brd.getBxStart(),brd.getByStart()}),
	goal(rng,brd,snek)
{
	for(int i=0; i<10000; i++){
		block[i]=Block(brd);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(){
	const float dt=fr.mark();
	if(wnd.kbd.KeyIsPressed(VK_SPACE)){
		snekMovePer=10.0f;
		if(wnd.kbd.KeyIsPressed(VK_CONTROL)){
			snekMovePer=3.0f;
		} else{
			snekMovePer=10.0f;
		}
	} else{
		snekMovePer=permSnake;
	}
	snekMovePer=snekMovePer/60.0f;
	if (!gameOver && gameOn) {
		brd.drawBoarder();
		if (wnd.kbd.KeyIsPressed(VK_UP) && !delta_loc.last(0, 1) && moveExc && !delta_loc.last(0,-1)) {
			delta_loc = { 0,-1 };
			moveExc = false;
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN) && !delta_loc.last(0, -1) && moveExc&&!delta_loc.last(0,1)) {
			delta_loc = { 0,1 };
			moveExc = false;
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && !delta_loc.last(-1, 0) && moveExc&&!delta_loc.last(1,0)) {
			delta_loc = { 1,0 };
			moveExc = false;
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT) && !delta_loc.last(1, 0) && moveExc&&!delta_loc.last(-1,0)) {
			delta_loc = { -1,0 };
			moveExc = false;
		}
		snekMoveCNT=snekMoveCNT+dt;
		if (snekMoveCNT >= snekMovePer) {
			const Location next=snek.getNextHead(delta_loc);
			bool blockTest=false;
			for(int i=0; i<blockCount; i++){
				if(!blockTest&&
				   next.x==block[i].getLoc().x&&
				   next.y==block[i].getLoc().y){
					blockTest=true;
				}
			}
			if (!brd.isInsideBoard(next)||
				snek.isInTile(next,0)||
				blockTest) {
				gameOver = true;
			}
			else {
				if (next==goal.getLoc()) {
					snek.grow();
					eatCount++;
					if(eatCount%eatCycle==0){
						blockCount++;
					}
				}
				snek.moveBy(delta_loc);
				snekMoveCNT = 0.0f;
				moveExc = true;
				if(next==goal.getLoc()){
					goal.respawn(rng,brd,snek);
					for(int i=0; i<blockCount; i++){
						block[i].spawn(rng,brd,snek,goal);
					}
				}
			}
		}
	} else{
		if(wnd.kbd.KeyIsPressed(VK_RETURN)){
			gameOn=true;
		}
	}
}

void Game::ComposeFrame(){
	if(gameOn){
		for(int i=0; i<blockCount; i++){
			block[i].draw(brd);
		}
		snek.draw(brd);
		goal.draw(brd);
		if(gameOver){
			SpriteCodex::DrawGameOver(359,269,gfx);
		}
	}else{
		SpriteCodex::DrawTitle(293,220,gfx);
	}
}
