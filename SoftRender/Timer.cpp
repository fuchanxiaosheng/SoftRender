#include "Timer.h"

using namespace std::chrono;

float Timer::TimeTick()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}