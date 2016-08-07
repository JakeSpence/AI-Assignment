#include "DetectEnemy.h"

DetectEnemy::DetectEnemy()
{
}


DetectEnemy::~DetectEnemy()
{
}

BehaviourResult DetectEnemy::Execute(Agent * agent, float deltaTime)
{
	float dis = agent->GetPosition().Distance(agent->m_currentTarget->GetPos());
	if (dis > 100)
	{
		return Success;
	}
	else
	{
		return Failure;
	}
}
