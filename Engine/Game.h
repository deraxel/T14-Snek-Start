#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "board.h"
#include <random>
#include "snek.h"
#include "goal.h"
#include "block.h"
#include "framerate.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	FrameRate fr;
	void ComposeFrame();
	void UpdateModel();
	bool moveExc = true;
	MainWindow& wnd;
	Graphics gfx;
	Board brd;
	std::mt19937 rng;
	Snek snek;
	Location delta_loc = { 1,0 };
	Goal goal;
	static constexpr float permSnake = 60;
	float snekMovePer=1;
	float snekMoveCNT = 0;
	int eatCount=0;
	int eatCycle=5;
	int blockCount=0;
	bool gameOver = false;
	bool gameOn = false;
	Block block[10000];
};