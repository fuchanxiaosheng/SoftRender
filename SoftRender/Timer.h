#pragma once

#include <chrono>

class Timer
{
public:
	Timer() { last = std::chrono::steady_clock::now(); }
	float TimeTick();
private:
	std::chrono::steady_clock::time_point last;

};
