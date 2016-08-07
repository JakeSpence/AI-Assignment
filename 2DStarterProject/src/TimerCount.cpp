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
	else
	{
		if (difftime(agent->timer, currentTime) > 10)
		{
			return Failure;
		}
		else
		{
			return Success;
		}
	}

}
