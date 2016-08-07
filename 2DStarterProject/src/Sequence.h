#pragma once
#include "Composite.h"
class Sequence : public Composite
{
public:
	Sequence();
	~Sequence();

	BehaviourResult Execute(Agent* agent, float deltaTime);

protected:
	IBehaviour* currentChild = nullptr;
};

