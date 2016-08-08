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
	if (agent->m_currentTarget != nullptr)
	{
		return Success;
	}
	return Failure;
}
