#pragma once
#include "Composite.h"
class NextNode :	public Composite
{
public:
	NextNode();
	~NextNode();

	BehaviourResult Execute(Agent* agent, float deltaTime);
};

