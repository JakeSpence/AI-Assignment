#include "NextNode.h"



NextNode::NextNode()
{
}

NextNode::NextNode(std::vector<Node*> n)
{
	m_nodes = n;
}


NextNode::~NextNode()
{
}

BehaviourResult NextNode::Execute(Agent * agent, float deltaTime)
{
	Node* n = agent->m_finalTarget.front();
	if (agent->GetPosition().Distance(agent->m_currentTarget->GetPos()) < 50)
	{
		if (agent->m_path.size() == 1)
		{
			agent->m_finalTarget.push_back(n);
			agent->m_finalTarget.pop_front();
			agent->m_path = p.FindAStar(agent->m_nearbyNode, agent->m_finalTarget.front(), m_nodes);
		}
		else
		{
			agent->m_path.pop_front();
		}
	}

	agent->m_currentTarget = agent->m_path.front();

	if (agent->m_currentTarget != nullptr)
	{
		return Success;
	}
	return Failure;
}
