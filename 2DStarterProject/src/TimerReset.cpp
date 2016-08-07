#include "TimerReset.h"

TimerReset::TimerReset()
{
}


TimerReset::~TimerReset()
{
}

BehaviourResult TimerReset::Execute(Agent * agent, float deltaTime)
{
	agent->timer = -1.0f;
	if (agent->timer == -1.0f)
	{
		return Success;
	}
	else
	{
		return Failure;
	}
}
