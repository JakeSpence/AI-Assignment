#pragma once
#include "Composite.h"
class TimerReset : public Composite
{
public:
	TimerReset();
	~TimerReset();

	BehaviourResult Execute(Agent* agent, float deltaTime);
};

