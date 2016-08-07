#pragma once
#include "Composite.h"
class Distance : public Composite
{
public:
	Distance();
	~Distance();

	BehaviourResult Execute(Agent * agent, float deltaTime);
};

