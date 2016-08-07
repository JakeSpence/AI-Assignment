#pragma once
#include "Composite.h"
class MoveTo : public Composite
{
public:
	MoveTo();
	~MoveTo();

	BehaviourResult Execute(Agent * agent, float deltaTime);
};

