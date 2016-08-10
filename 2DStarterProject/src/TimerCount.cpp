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

	float f = difftime(currentTime, agent->m_timer);

	if (f < 5 /*&& difftime(agent->timer, currentTime) > 0*/)
	{
		return Success;
	}
	return Failure;
}
