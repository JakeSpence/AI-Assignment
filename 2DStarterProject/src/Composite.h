#pragma once
#include "IBehaviour.h"
#include <vector>
#include "Agent.h"

class Composite : public IBehaviour
{
public:
	Composite();
	~Composite();

	virtual BehaviourResult Execute(Agent* agent, float deltaTime) = 0;

protected:

	IBehaviour* pendingChild = nullptr;
};

