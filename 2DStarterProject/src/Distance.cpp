#include "Distance.h"

Distance::Distance()
{
}


Distance::~Distance()
{
}

BehaviourResult Distance::Execute(Agent * agent, float deltaTime)
{
	float dis = agent->GetPosition().Distance(agent->m_enemy->GetPosition());
	if (dis < 200)
	{
		return Success;
	}
	return Failure;

}