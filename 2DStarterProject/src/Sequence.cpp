#include "Sequence.h"



Sequence::Sequence()
{
}


Sequence::~Sequence()
{
}

BehaviourResult Sequence::Execute(Agent* agent, float deltaTime)
{
	currentChild = pendingChild;
	pendingChild = nullptr;

	if (currentChild == nullptr)
	{
		currentChild = m_behaviourList.front();
	}

	while (currentChild != m_behaviourList.back())
	{
		BehaviourResult result = currentChild->Execute(agent, deltaTime);
		if (result == Success)
		{
			return Success;
		}
		else if (result == Failure)
		{
			return Failure;
		}
		else if (result == Pending)
		{
			pendingChild = currentChild;
			return Pending;
		}
	}
	return Success;
}
