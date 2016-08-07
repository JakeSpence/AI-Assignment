#pragma once
#include "Composite.h"
class TimerCount : public Composite
{
public:
	TimerCount();
	~TimerCount();

	BehaviourResult Execute(Agent* agent, float deltaTime);
};

