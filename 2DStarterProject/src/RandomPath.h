#pragma once
#include "Composite.h"
class RandomPath : public Composite
{
public:
	RandomPath();
	~RandomPath();

	BehaviourResult Execute(Agent * agent, float deltaTime);
};

