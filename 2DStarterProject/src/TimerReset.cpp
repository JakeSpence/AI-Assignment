#include "TimerReset.h"
#include <time.h>

TimerReset::TimerReset()
{
}


TimerReset::~TimerReset()
{
}

BehaviourResult TimerReset::Execute(Agent * agent, float deltaTime)
{	
	time(&agent->timer);
	return Success;
}
