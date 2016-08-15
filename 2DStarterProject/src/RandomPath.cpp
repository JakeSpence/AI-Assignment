#include "RandomPath.h"
#include <stdlib.h>
#include <time.h>


RandomPath::RandomPath()
{
	srand(time(NULL));
}


RandomPath::~RandomPath()
{
}

BehaviourResult RandomPath::Execute(Agent * agent, float deltaTime)
{
	int randomNode = rand() % agent->m_nearbyNode->GetConnections().size();
	int count = 0;
	float dis = agent->m_nearbyNode->GetPos().Distance(agent->GetPosition());

	if (dis < 5)
	{
		for (Edge e : agent->m_nearbyNode->GetConnections())
		{
			if (count == randomNode && e.GetConnectionNode() != agent->m_nearbyNode)
			{
				agent->m_currentTarget = e.GetConnectionNode();
				return Success;
			}
			count++;
		}
	}
	else if(agent->m_nearbyNode->GetPos().Distance(agent->GetPosition()) < 5)
	{
		return Success;
	}
	return Failure;
}
