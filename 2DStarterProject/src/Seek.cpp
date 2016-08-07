#include "Seek.h"
#include "PathFinder.h"

MoveTo::MoveTo()
{
}


MoveTo::~MoveTo()
{
}

BehaviourResult MoveTo::Execute(Agent * agent, float deltaTime)
{
	/*if (agent->m_currentTarget != nullptr)
	{
		PathFinder path;
		agent->m_path = path.FindAStar(agent->m_nearbyNode, agent->m_currentTarget);
	}

	Node* n = agent->m_path.front();
	for (Node* n : agent->m_path)
	{
		if (n == agent->m_nearbyNode)
		{
			
		}
	}*/
	Vector2 prevPos = agent->GetPosition();
	Vector2 v = agent->m_currentTarget->GetPos() - agent->GetPosition();
	v.Normalise();
	v = v * agent->m_maxVelocity;
	agent->m_force = v - agent->m_velocity;

	agent->m_velocity += (agent->m_force * deltaTime);
	agent->GetPosition() += (agent->m_velocity * deltaTime);

	if (prevPos != agent->GetPosition())
	{
		return Success;
	}

	return Failure;
}
