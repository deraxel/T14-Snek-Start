#pragma once
#include "Graphics.h"
#include "location.h"

class Board {
private:
	static constexpr int dimension = 20;
	static constexpr int width = 34;
	static constexpr int height = 24;
	int bX=20;
	int bY=20;
	static constexpr int boarderWidth=4;
	static constexpr int borderPadding=2;
	static constexpr Color borderColor=Colors::Yellow;
	static constexpr Color fieldColor=Colors::Black;
	Graphics& gfx;
public:
	Board(Graphics&);
	void drawCell(const Location&, Color);
	int getW() const;
	int getH() const;
	int getBxStart() const;
	int getByStart() const;
	bool isInsideBoard(const Location&)const;
	void drawSnek(const Location&,const int,const int);
	void drawSnekHead(const Location&,const int);
	void drawSnekBodyEven(const Location&,const int);
	void drawSnekBodyOdd(const Location&,const int);
	void drawSnekTail(const Location&,const int);
	void drawGoal(const Location&);
	void drawBlock(const Location&);
	void drawBoarder();
};