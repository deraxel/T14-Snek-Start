#include "location.h"

void Location::add(const Location& val) {
	x += val.x;
	y += val.y;
}

bool Location::last(const int xT,const int yT)const {
	return (xT == x) && (yT == y);
}

bool Location::operator==(const Location & lhs) const{
	return x == lhs.x&&y == lhs.y;
}
