#pragma once
#include "board.h"
#include "location.h"

class Snek {
private:
	class Segment {
	private:
		Location loc;
		Color c;
		int spriteGen;
		int dir;
	public:
		void follow(const Segment&);
		void initHead(const Location&);
		void initBody(int);
		void draw(Board&,bool,int const)const;
		void moveBy(const Location&);  
		Location getLoca() const;
		Location getHead();
	};
	static constexpr int maxSeg = 10000;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	Segment segments[maxSeg];
	int nSegs = 1;
public:
	Snek(const Location&);
	void moveBy(const Location&);
	void grow();
	void draw(Board&) const;
	Location getNextHead(const Location&)const;
	bool isInTile(const Location&,int)const;
	Location getHead();
};