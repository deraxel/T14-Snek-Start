#pragma once
class Location {
public:
	void add(const Location&);
	bool last(const int,const int)const;
	int x;
	int y;
	bool operator == (const Location& lhs)const;
};