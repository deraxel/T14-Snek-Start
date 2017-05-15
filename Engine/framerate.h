#pragma once
#include <chrono>

class FrameRate{
private:
	std::chrono::steady_clock::time_point last;
public:
	FrameRate();
	float mark();
};