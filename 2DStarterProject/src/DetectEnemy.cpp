#include "DetectEnemy.h"

DetectEnemy::DetectEnemy()
{
}


DetectEnemy::~DetectEnemy()
{
}

BehaviourResult DetectEnemy::Execute(Agent * agent, float deltaTime)
{
	float dis = agent->GetPosition().Distance(agent->m_enemy->GetPosition());
	if (dis < 200)
	{
		agent->m_currentTarget = agent->m_enemy->m_nearbyNode;
		return Success;
	}
	else
	{
		return Failure;
	}
}
