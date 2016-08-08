#include "Distance.h"

Distance::Distance()
{
}


Distance::~Distance()
{
}

BehaviourResult Distance::Execute(Agent * agent, float deltaTime)
{
	if (agent->m_currentTarget->GetPos().Distance(agent->m_enemy->GetPosition()) < 50)
	{
		return Success;
	}
	return Failure;
}