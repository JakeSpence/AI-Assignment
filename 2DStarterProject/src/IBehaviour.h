#pragma once
#include "PathFinder.h"

class Agent;
enum BehaviourResult
{
	Success,
	Failure,
	Pending
};

class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual BehaviourResult Execute(Agent* thisAgent, float deltaTime) = 0;

	void AddChild(IBehaviour* b);

	std::list<IBehaviour *> m_behaviourList;

private:
};

