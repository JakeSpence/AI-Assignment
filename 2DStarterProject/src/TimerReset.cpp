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
	time(&agent->m_timer);
	return Success;
}
