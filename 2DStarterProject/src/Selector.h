#pragma once
#include "Composite.h"
class Selector : public Composite
{
public:
	Selector();
	~Selector();

	BehaviourResult Execute(Agent* agent, float deltaTime);

private:
	IBehaviour* currentChild = nullptr;
};

