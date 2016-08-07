#pragma once
#include "Composite.h"
class DetectEnemy : public Composite
{
public:
	DetectEnemy();
	~DetectEnemy();

	BehaviourResult Execute(Agent * agent, float deltaTime);
};

