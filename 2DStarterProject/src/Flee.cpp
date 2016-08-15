#include "Flee.h"

Flee::Flee()
{
}


Flee::~Flee()
{
}

BehaviourResult Flee::Execute(Agent * agent, float deltaTime)
{	
	int randomNode = rand() % agent->m_nearbyNode->GetConnections().size();
	int count = 0;

	for (Edge e : agent->m_nearbyNode->GetConnections())
	{
		if (e.GetConnectionNode() != agent->m_enemy->m_nearbyNode && count == randomNode)
		{
			agent->m_currentTarget = e.GetConnectionNode();
			return Success;
		}
	}
	return Failure;
}
