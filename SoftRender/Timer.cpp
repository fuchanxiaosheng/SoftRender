#include "Timer.h"

using namespace std::chrono;

float Timer::TimeTick()
{
	last = steady_clock::now();
	const duration<float> deltaTime = last - secStart;
	if (deltaTime.count() > 1)
	{
		secStart = last;
		fps = frameCount;
		frameCount = 0;
		return fps;
	}
	frameCount++;
	return fps;
}

float Timer::TimeMask()
{
	return duration<float>(steady_clock::now() - start).count();
}