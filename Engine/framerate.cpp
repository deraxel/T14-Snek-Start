#include "framerate.h"

using namespace std::chrono;

FrameRate::FrameRate(){
	last=steady_clock::now();
}

float FrameRate::mark(){
	const steady_clock::time_point old=last;
	last=steady_clock::now();
	const duration<float> timeDisparity=last-old;
	return timeDisparity.count();
}