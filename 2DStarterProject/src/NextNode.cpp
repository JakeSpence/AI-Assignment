#include "NextNode.h"



NextNode::NextNode()
{
}


NextNode::~NextNode()
{
}

BehaviourResult NextNode::Execute(Agent * agent, float deltaTime)
{
	agent->NextNode();
	if (agent->GetTarget() != nullptr)
	{
		return Success;
	}
	else
	{
		agent->PathFind(agent->m_nearbyNode, agent->m_finalTarget);
		if (agent->m_nearbyNode->GetParent() != nullptr)
		{
			return Success;
		}
	}
	return Failure;
}
