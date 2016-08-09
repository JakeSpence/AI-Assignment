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

	for (Edge e : agent->m_nearbyNode->GetConnections())
	{
		if (count == randomNode)
		{
			agent->m_currentTarget = e.GetConnectionNode();
			return Success;
		}
		count++;
	}
	return Failure;
}
