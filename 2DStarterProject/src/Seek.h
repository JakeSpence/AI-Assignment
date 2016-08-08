#pragma once
#include "Composite.h"
class Seek : public Composite
{
public:
	Seek();
	~Seek();

	BehaviourResult Execute(Agent * agent, float deltaTime);
};

