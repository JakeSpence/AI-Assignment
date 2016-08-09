#include "TimerCount.h"
#include <time.h>

TimerCount::TimerCount()
{
}


TimerCount::~TimerCount()
{
}

BehaviourResult TimerCount::Execute(Agent * agent, float deltaTime)
{
	time_t currentTime;
	time(&currentTime);

	if (difftime(agent->timer, currentTime) < 5 && difftime(agent->timer, currentTime) > 0)
	{
		return Success;
	}
	return Failure;
}
