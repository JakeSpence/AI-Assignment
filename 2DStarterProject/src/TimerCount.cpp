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
	if (agent->timer == -1)
	{
		time(&agent->timer);
	}
	if (difftime(currentTime, agent->timer) > 5)
	{
		return Failure;
	}
	return Success;
}
