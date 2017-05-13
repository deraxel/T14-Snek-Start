#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );
	static void DrawTitle( int x,int y,Graphics& gfx );
	static void drawHeadUp(int,int,Graphics&);
	static void drawHeadDown(int,int,Graphics&);
	static void drawHeadLeft(int,int,Graphics&);
	static void drawHeadRight(int,int,Graphics&);
	static void drawBodyUp(int,int,Graphics&);
	static void drawBodyDown(int,int,Graphics&);
	static void drawBodyRight(int,int,Graphics&);
	static void drawBodyLeft(int,int,Graphics&);
	static void drawTailRight(int,int,Graphics&);
	static void drawTailLeft(int,int,Graphics&);
	static void drawTailDown(int,int,Graphics&);
	static void drawTailUp(int,int,Graphics&);
	static void drawGoal(int,int,Graphics&);
	static void drawBlock(int,int,Graphics&);
};