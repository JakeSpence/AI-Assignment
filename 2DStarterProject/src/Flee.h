#pragma once
#include "Composite.h"
class Flee : public Composite
{
public:
	Flee();
	~Flee();

	BehaviourResult Execute(Agent * agent, float deltaTime);
};

