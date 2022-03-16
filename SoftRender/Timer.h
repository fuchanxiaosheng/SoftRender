#pragma once

#include <chrono>

class Timer
{
public:
	Timer() 
	{ 
		last = std::chrono::steady_clock::now(); 
		start = std::chrono::steady_clock::now();
		secStart = std::chrono::steady_clock::now();
		fps = 0;
		frameCount = 0;
	}
	float TimeTick();
	float TimeMask();
private:
	std::chrono::steady_clock::time_point last;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point secStart;
	float fps;
	int frameCount;
};
